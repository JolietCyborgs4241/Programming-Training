#include <frc/trajectory/TrajectoryUtil.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <exception>


#include "commands/PathGroup.h"


using namespace std;


//  PathGroup class

PathGroup::PathGroup(string tempGroupName, string tempDirectory) {

    groupName     = tempGroupName; 

    groupDir      = tempDirectory;

    groupFilePath = tempDirectory + tempGroupName; 

    getPathFiles(groupFilePath);

}


std::string PathGroup::getGroupName() {

    return groupName;
}


int PathGroup::getGroupPathsAvailable() {

    return groupPathsAvailable;
}

std::string PathGroup::getGroupSegPathName(int segment) {

    if (segment < groupPathsAvailable && segment >= 0) {
         return pathFiles[segment];
    } else {
        return "";
    }
}


frc::Trajectory PathGroup::getGroupSegTrajectory(int segment, bool& success) {

    frc::Trajectory segment_trajectory;

    string json_file = getJsonFile(getGroupSegPathName(segment));

    success = true; 

    try {

        segment_trajectory = frc::TrajectoryUtil::FromPathweaverJson(json_file);
    }
    catch(...) {

        success = false; 
    } 

    return segment_trajectory;      // ignore if success value not true
}


int PathGroup::getFileTypeIndex(string file) {

    int index = 0;

    while(file[index] != '.')
    {
        index++;
    }

    return index;
}


string PathGroup::convertFromPathToJson(string file) {

    file.replace(getFileTypeIndex(file), PATH_FILE_TYPE.length(), JSON_FILE_TYPE);

    return file;
}


string PathGroup::getJsonFile(string file) {
    
    file = groupDir + "../output/" + convertFromPathToJson(file);

    return file;
}


void PathGroup::getPathFiles(string groupFile) {

    ifstream readGroupFile;

    readGroupFile.open(groupFile);
    
    int segment = 0;

    while (!readGroupFile.eof()) {
        getline(readGroupFile, pathFiles[segment]);
 
        segment++;
    }

    readGroupFile.close();

    groupPathsAvailable = segment; 
}
