#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    // getting compile time version
    cout << "Compile-time" << endl;
    cout << "\tOpenCV version   : " << CV_VERSION << endl;
    cout << "\tMajor version    : " << CV_MAJOR_VERSION << endl;
    cout << "\tMinor version    : " << CV_MINOR_VERSION << endl;
    cout << "\tSubminor version : " << CV_SUBMINOR_VERSION << endl;
    
    // getting run time version

    string version = CV_VERSION;
    // cout << version.compare("3.4.2") >=  << endl;
    if (version.compare("3.4.2") >= 0)
    {
        cout << "Run-time" << endl;
        cout << "\tOpenCV version   : " << getVersionString() << endl;
        cout << "\tMajor version    : " << getVersionMajor() << endl;
        cout << "\tMinor version    : " << getVersionMinor() << endl;
        cout << "\tRevision version : " << getVersionRevision() << endl;   
    }


    return 0;
}
