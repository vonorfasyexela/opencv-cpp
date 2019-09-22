#include <opencv2/opencv.hpp>

#if (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 4 && CV_SUBMINOR_VERSION >= 3) || \
    (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 5) || \
    (CV_MAJOR_VERSION >= 4)

    // we should include this in order to query backends in runtime
    #include <opencv2/videoio/registry.hpp>
    #define MODERN_OPENCV
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
#ifdef MODERN_OPENCV
    vector<VideoCaptureAPIs> backends = videoio_registry::getBackends();
    cout << "All available runtime backends:" << endl;
    for (size_t i = 0; i < backends.size(); i++)
    {
        cout << "\t" << videoio_registry::getBackendName(backends.at(i)) << endl;
    } 
#endif

    // now the user should enter what he wants to open
    cout << "Enter the input (URL for the stream, the index for the camera): ";
    string input;
    cin >> input;

    // here we decide what's the type of the input
    VideoCapture cap;
    if (is_number(input))
    {
        cout << "Type of the input is camera" << endl;
    #ifdef MODERN_OPENCV
        // determine camera backends
        vector<VideoCaptureAPIs> camera_backends = videoio_registry::getCameraBackends();
        cout << "Available camera backends:" << endl;
        for (size_t i = 0; i < camera_backends.size(); i++)
        {
            cout << "\t" << videoio_registry::getBackendName(camera_backends.at(i)) << endl;
        } 
    #else
        cap.open(stoi(input));
    #endif
    }
    else
    {
        cout << "Type of the input is stream" << endl;
    #ifdef MODERN_OPENCV
        // determine stream backends
        vector<VideoCaptureAPIs> stream_backends = videoio_registry::getStreamBackends();
        // add CAP_ANY backend to the beginning
        stream_backends.insert(stream_backends.begin(), CAP_ANY);
        cout << "Available stream backends:" << endl;
        for (size_t i = 0; i < stream_backends.size(); i++)
        {
            cout << "\t" << i << " - " << videoio_registry::getBackendName(stream_backends.at(i)) << endl;
        } 
        
        cout << "Select the number: ";
        string sel_backend_index_str;
        cin >> sel_backend_index_str;

        int sel_backend_index = stoi(sel_backend_index_str);
        cout << "We are opening stream " << input << endl;
        cap.open(input, stream_backends.at(sel_backend_index));
    #else
        cap.open(input);
    #endif
    }

    if (!cap.isOpened()) 
    {
        cerr << "ERROR! Unable to open the input" << endl;
        return -1;
    }
#ifdef MODERN_OPENCV
    cout << "We are working through " << cap.getBackendName() << " as a backend" << endl;
#endif
    // getting properties
    cout << "Video: " << cap.get(CAP_PROP_FRAME_WIDTH) << "x" << cap.get(CAP_PROP_FRAME_HEIGHT) << "@" << cap.get(CAP_PROP_FPS) << "fps" << endl;

    // start playing
    cout << "Start playing" << endl;
    cout << "Press q to terminate" << endl;
    
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
        if (waitKey(5) == 'q')
        {
            break;
        }
    }

    return 0;
}
