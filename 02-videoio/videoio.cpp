#if (CV_MAJOR_VERSION < 3)
#include <opencv2/videoio/videoio.hpp>
#else
#include <opencv2/videoio.hpp>
#endif // (CV_MAJOR_VERSION < 3)
// in order to obtain backends in runtime we should include this
#include <opencv2/videoio/registry.hpp>
#include <iostream>

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
