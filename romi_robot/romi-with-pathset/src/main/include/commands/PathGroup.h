//  path_group.h
//
//  Cyborgs classes for dealing with PathWeaver-generated paths, groups, and trajectories

#pragma once

#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>

#include <cstring>
#include <fstream>
#include <iostream>


#define MAX_SEG_PATHS_IN_GROUP       10

using namespace std;

class PathGroup {

    public:

    // the first param is the actual group file to open, the directory of the path to where the group files are
    //
    // to get to a specific group, the path will be "directory" + "/Groups/" + "groupName"
    PathGroup(std::string groupName, std::string directory);

    // returns the name of the group - passed at creation time
    std::string getGroupName();

    // returns the nuber of segments in this group
    //
    // each segment is a path filename - one line per path in the group file
    int getGroupPathsAvailable();

    // returns the path segment name for a specific index in a group
    // indexes start at 0
    std::string getGroupSegPathName(int seg);
    
    // returns the FRC trajectory for a specific path segment in a group
    // indexes start at 0
    frc::Trajectory getGroupSegTrajectory(int seg, bool& success);
    

    protected:

    std::string groupName;
    std::string groupDir;
    std::string groupFilePath;

    std::string const PATH_FILE_TYPE = ".path";
    std::string const JSON_FILE_TYPE = ".wpilib.json";

    // we can store just the path file names in here or the full path to the path segments
    //
    // in any case, the group file stores just the path segment name "xyz.path"
    //
    // to get to the actual path segment file, the path would be "directory" + "/Paths/" + pathfile
    std::string pathFiles[MAX_SEG_PATHS_IN_GROUP];

    int getFileTypeIndex(string file);// finds at what index a file string's file type is (EX: where .path of "something.path" begins)

    string convertFromPathToJson(string file);// converts  file from "something.path" to "something.wpilib.json"

    string getJsonFile(string file);// provides a json file based on the groupDir and the file provided ("".wpilib.json" type should be provided)

    void getPathFiles(string file); 

    int groupPathsAvailable = 0; 
};

