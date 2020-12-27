#include "algorithm.h"


// reflectance["center"] > threshold     white
geometry_msgs::Twist control(
        std::unordered_map<std::string, double> proximity,
        std::unordered_map<std::string, double> reflectance,
        double threshold) {
    geometry_msgs::Twist msg;
    if (reflectance["left"] < threshold && reflectance["right"] < threshold && reflectance["center"] < threshold) {
        msg.linear.x = 0.1;
        msg.angular.z = 0;
    } else if (reflectance["center"] < threshold) {
        if (reflectance["left"] >= threshold) {
            msg.linear.x = 0;
            msg.angular.z = -M_PI / 4;
        } else if (reflectance["right"] >= threshold) {
            msg.linear.x = 0;
            msg.angular.z = M_PI / 4;
        }
    } else {
        msg.linear.x = 0;
        msg.angular.z = 0;
    }
    return msg;
}
