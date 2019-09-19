#include <opencv2/opencv.hpp>
#include <opencv2/videoio/registry.hpp>

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
