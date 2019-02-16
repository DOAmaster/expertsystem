#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

// Define a constant for the number of lines to read
#define NUM_READ_LINES 20
#define NUM_READ_LINES2 80

bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
    // Open the File
    std::ifstream in(fileName.c_str());
    // Check if object is valid
    if(!in)
    {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }

    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}

int main() {

    //vectors storing numbers using lines of array to populate
    vector<float> firstNum;
    vector<float> secondNum;
    vector<float> realResults;
    vector<string> vecOfStr;

	vector<float> testingVector;

    bool result = getFileContent("testingData.txt", vecOfStr);

	// Array of line numbers each line being no more than 100 chars
	char testingArray[NUM_READ_LINES][100];
	char trainingArray[NUM_READ_LINES2][100];
	int counter = 0;
	int counter2 = 0;

	// Open our file
	ifstream inFile("testingData.txt",ifstream::in);

	// If we can read/write great
	if (inFile.good()) {

		// Read throuthe file and load into array
		while (!inFile.eof() && (counter < NUM_READ_LINES)) {
            //counter++;
			inFile.getline(testingArray[counter],100);
			counter++;
		}

	}
	inFile.close();	

	// Open our file
	ifstream inFile2("trainingData.txt",ifstream::in);

	// If we can read/write great
	if (inFile2.good()) {

		// Read throuthe file and load into array
		while (!inFile2.eof() && (counter2 < NUM_READ_LINES2)) {
			inFile2.getline(trainingArray[counter2],100);
			counter2++;
		}

	}
	inFile2.close();	

    //split logic takes "1.5 , 2" turn it into 1.5
    /*
    float number;
    int pos = line.find(",");
    string sub = line.substr(pos+1);
    int resultTemp = stoi(sub);
    realResults.push_back(resultTemp);
    while (iss >> number ) {
        firstNum.push_back(number);
    }
    */

	// Loop through the array which we just put together
    cout << "Scanning testingArray... " << endl;
	for (int i = 0; i < counter; i++) {

    string dataString = testingArray[i];

    int pos = dataString.find("\t");

    string str1 = dataString.substr(0, pos);
    string str2 = dataString.substr(pos, pos+3);
    string str3 = dataString.substr(pos+4);

    string classString = "";

    cout << "str1 = " << str1 << " str2 = " << str2 <<  " str3 = " << str3 << endl;

    float floatTemp1;
    float floatTemp2;
    float floatTemp3;

    //take testingArray[i] string and substring into 3 parts
    //"float" tab tab "float" tab tab "string"


    //cout << testingArray[i] << endl;
    }

	// Loop through the array which we just put together
    cout << "Printing testingArray: " << endl;
	for (int i = 0; i < counter; i++) {
		//cout << testingArray[i] << endl;
	}


	// Loop through the array which we just put together
    cout << "Printing trainingArray: " << endl;
	for (int i = 0; i < counter2; i++) {
		//cout << trainingArray[i] << endl;
	}

	return 0;
}

