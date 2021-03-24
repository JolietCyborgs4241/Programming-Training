//  path_set.h
//
//  Cyborgs clsses for dealing with PathWeaver-generated paths, groups, and trajectories

#pragma once

#include <cstring>

#include "commands/PathGroup.h"


#define MAX_PATH_GROUPS          10


typedef struct {
    PathGroup *pathGroup;
    string     fullGroupPath;
    string     groupName;
} GROUP_INFO;


class PathSet {

    public:

    // instantiating the class loads groups from default directory or specified directory
    PathSet(string pathSeqFolder);
    //PathSet() : PathSet(nullptr) {};

    // return the number of groups available
    int getGroupsAvailable();

    // return the number of poath segments available for a specific group
    int getGroupPathsAvailable(int groupIndex);
    int getGroupPathsAvailable(string groupName);

    // return group name group index or name - useful for searching
    string getGroupName(int i);
    int getGroupIndex(string groupName);
    
    // return group name group index or name - useful for searching
    string getGroupPath(int groupIndex, int pathIndex);
    string getGroupPath(string groupName, int pathIndex);
    
    // return a specific group trajectory by index or name
    frc::Trajectory getGroupSegTrajectory(int groupIndex, int seg, bool& status);
    frc::Trajectory getGroupSegTrajectory(string groupName, int seg, bool& status);


    protected:

    //PathGroup *pathGroups[MAX_PATH_GROUPS];

    GROUP_INFO groups[MAX_PATH_GROUPS];

    int numOfPathGroups = 0;

    const string GROUP_FOLDER = "/Groups/";
    const string PATHS_FOLDER = "/Paths/";
};
