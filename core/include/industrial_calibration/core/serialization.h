#pragma once

#include <industrial_calibration/core/exceptions.h>

#include <cxxabi.h>
#include <Eigen/Dense>

namespace industrial_calibration
{
template <typename FloatT>
inline Eigen::Transform<FloatT, 3, Eigen::Isometry> toIsometry(const Eigen::Vector3d& trans,
                                                               const Eigen::Vector3d& euler_zyx)
{
  return Eigen::Translation3d(trans) * Eigen::AngleAxisd(euler_zyx(2), Eigen::Vector3d::UnitZ()) *
         Eigen::AngleAxisd(euler_zyx(1), Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(euler_zyx(0), Eigen::Vector3d::UnitX());
}

inline void writeTransform(std::stringstream& stream, const Eigen::Isometry3d& transform)
{
  Eigen::IOFormat io_format(4, 0, " ", "\n", "[", "]");
  stream << "\txyz: " << transform.translation().transpose().format(io_format) << "\n";
  stream << "\trpy: " << transform.rotation().eulerAngles(2, 1, 0).reverse().transpose().format(io_format) << "\n";
  stream << "\tq (xyzw): " << Eigen::Quaterniond(transform.rotation()).coeffs().transpose().format(io_format);
}

}  // namespace industrial_calibration

