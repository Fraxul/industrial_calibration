#include <industrial_calibration/core/camera_intrinsics.h>

using namespace industrial_calibration;

namespace industrial_calibration
{
std::ostream& operator<<(std::ostream& stream, const CameraIntrinsics& intr)
{
  stream << "Camera intrinsics:\n\tfx = " << intr.fx() << "\n\taspect = " << intr.aspect() << "\n\tcx = " << intr.cx()
         << "\n\tcy = " << intr.cy();
  return stream;
}

}  // namespace industrial_calibration
