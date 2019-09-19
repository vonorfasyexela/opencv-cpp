#include <opencv2/opencv.hpp>
#if (CV_MAJOR_VERSION < 3)
#error "Your OpenCV version is too old for this shit"
#else
#include <opencv2/videoio/registry.hpp>
#endif

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    vector<VideoCaptureAPIs> backends = cv::videoio_registry::getBackends();
    for (size_t i = 0; i < backends.size(); i++)
    {
        cout << videoio_registry::getBackendName(backends[i]) << endl;
    } 
    return 0;
}
