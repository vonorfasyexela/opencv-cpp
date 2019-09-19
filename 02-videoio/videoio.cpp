#include <opencv2/opencv.hpp>
#if (CV_MAJOR_VERSION < 3)
#error "Your OpenCV version is too old for this shit"
#else
// we should include this in order to query backends in runtime
#include <opencv2/videoio/registry.hpp>
#endif

using namespace std;
using namespace cv;

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char const *argv[])
{
    // first of all we're getting the list of available backends and print their names
    vector<VideoCaptureAPIs> backends = videoio_registry::getBackends();
    cout << "All available runtime backends:" << endl;
    for (size_t i = 0; i < backends.size(); i++)
    {
        cout << "\t" << videoio_registry::getBackendName(backends.at(i)) << endl;
    } 

    // determine stream backends
    vector<VideoCaptureAPIs> stream_backends = videoio_registry::getStreamBackends();
    cout << "Stream backends:" << endl;
    for (size_t i = 0; i < stream_backends.size(); i++)
    {
        cout << "\t" << videoio_registry::getBackendName(stream_backends.at(i)) << endl;
    } 

    // determine camera backends
    vector<VideoCaptureAPIs> camera_backends = videoio_registry::getCameraBackends();
    cout << "Camera backends:" << endl;
    for (size_t i = 0; i < camera_backends.size(); i++)
    {
        cout << "\t" << videoio_registry::getBackendName(camera_backends.at(i)) << endl;
    } 

    cout << "Enter the input (URL for the stream, the index for the camera): ";
    string input;
    cin >> input;

    // open input
    VideoCapture cap;
    if (is_number(input))
    {
        cout << "We are opening camera " << stoi(input) << endl;
        cap.open(stoi(input));
    }
    else
    {
        cout << "We are opening stream " << input << endl;
        cap.open(input);
    }

    if (!cap.isOpened()) 
    {
        cerr << "ERROR! Unable to open the input" << endl;
        return -1;
    }
    cout << "We are working through " << cap.getBackendName() << " as a backend" << endl;

    // start playing
    cout << "Start playing" << endl << "Press any key to terminate" << endl;
    Mat frame;
    while (42)
    {
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) 
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow(input, frame);
        if (waitKey(5) >= 0)
        {
            break;
        }
    }

    return 0;
}
