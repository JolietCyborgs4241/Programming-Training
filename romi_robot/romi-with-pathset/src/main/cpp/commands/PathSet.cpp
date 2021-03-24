#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

#include <dirent.h>
#include <sys/stat.h>

using namespace std;

#include "commands/PathGroup.h"
#include "commands/PathSet.h"


// PathSet class

PathSet::PathSet(string pathFolder) {

    // create the full path name to the directory containing the group files
    string fullGroupDirPath = pathFolder + GROUP_FOLDER;

    struct stat info;

    // open the dir and start processing the group names
    if (auto dir = opendir(fullGroupDirPath.c_str())) {

        while (auto dirEntry = readdir(dir)) {

            // get the information about this file system entry
            if (stat((fullGroupDirPath + "/" + dirEntry->d_name).c_str(), &info) != 0) {
                cerr << "PathSet(): stat() error on \"" << fullGroupDirPath
                     << "/" << dirEntry->d_name << "\": error: " <<
                     strerror(errno) << endl;

                return;
            }

            // check to see if it's a file since all we care about are files
            // files are considered to be "regular" (a historical thing)

            if (S_ISREG(info.st_mode)) {

                // cout << "dirEntry->d_name: \"" << dirEntry->d_name << "\"" << endl;
                // cout << "fullGroupDirPath: \"" << fullGroupDirPath << "\"" << endl;

                groups[numOfPathGroups].pathGroup     = new PathGroup(dirEntry->d_name, fullGroupDirPath);
                groups[numOfPathGroups].fullGroupPath = fullGroupDirPath + dirEntry->d_name;
                groups[numOfPathGroups].groupName     = dirEntry->d_name;

                if (numOfPathGroups < (MAX_PATH_GROUPS - 1)) {
                    numOfPathGroups++;
                } else {
                    closedir(dir);
                    return;
                }
            }
        }

        closedir(dir);

    } else {

         cerr << "PathSet(): opendir() error on \"" << fullGroupDirPath 
              << "\": error: " << strerror(errno) << endl;
    }
}


int PathSet::getGroupsAvailable() {

    return numOfPathGroups;
}


int PathSet::getGroupPathsAvailable(int groupIndex) {

    if (groupIndex < 0 || groupIndex >= numOfPathGroups) {
        return -1;
    } else {
        return groups[groupIndex].pathGroup->getGroupPathsAvailable();
    }
}


int PathSet::getGroupPathsAvailable(string groupName) {

    int groupIndex;

    if ((groupIndex = getGroupIndex(groupName)) == -1) {
        return -1;
    }

    if (groupIndex < 0 || groupIndex >= numOfPathGroups) {
        return -1;
    } else {
        return groups[groupIndex].pathGroup->getGroupPathsAvailable();
    }
}


string PathSet::getGroupName(int i) {

    if (i < 0 || i >= numOfPathGroups) {

        return "";

    } else {

        return groups[i].groupName;
    }
}


// return the index of a group by name
//
// return -1 if group not found
int PathSet::getGroupIndex(string groupName) {

    for (auto i = 0 ; i < numOfPathGroups ; i++) {

        if (groupName.compare(groups[i].groupName) == 0) {

            return i;
        }
    }

    return -1;
}


string PathSet::getGroupPath(int group, int index) {

    if (group < 0 || group >= numOfPathGroups) {
        return "";
    }

    if (index < 0 || index > groups[group].pathGroup->getGroupPathsAvailable()) {
        return "";
    }

    return groups[group].pathGroup->getGroupSegPathName(index);
}


string PathSet::getGroupPath(string name, int pathIndex) {

    int groupIndex;
    
    if ((groupIndex = getGroupIndex(name)) == -1) {
        return "";
    }

    if (pathIndex < 0 || pathIndex > groups[groupIndex].pathGroup->getGroupPathsAvailable()) {
        return "";
    }

    return groups[groupIndex].pathGroup->getGroupSegPathName(pathIndex);
}


frc::Trajectory PathSet::getGroupSegTrajectory(int groupIndex, int seg, bool& status) {

    frc::Trajectory trajectory;
    bool            success;

    if (groupIndex < 0 || groupIndex >= numOfPathGroups) {
        status = false;
        return trajectory;      // yes, it's uninitialized but you shouldn't look at it if status isn't true!
    }

    trajectory = groups[groupIndex].pathGroup->getGroupSegTrajectory(seg, success);
    status = success;
    return trajectory;
}


frc::Trajectory PathSet::getGroupSegTrajectory(string groupName, int seg, bool& status) {

    frc::Trajectory trajectory;
    bool            success;
    int             groupIndex;

    if ((groupIndex = getGroupIndex(groupName)) == -1) {
        status = false;
        return trajectory;  // uninitialized if getGroupIndex() fails!
    }

    trajectory = getGroupSegTrajectory(groupIndex, seg, success);
    status = success;
    return trajectory;
}


