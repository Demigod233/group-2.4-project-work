include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;


class HotelBooking {
private:
    string guestName;
    string phoneNumber;
    string roomType;
    int roomNumber;
    int numberOfNights;
    double roomRate;
    double totalCost;
    string paymentStatus;
    string bookingStatus;

public:
    // Constructor
    HotelBooking() {
        guestName = "";
        phoneNumber = "";
        roomType = "";
        roomNumber = 0;
        numberOfNights = 0;
        roomRate = 0.0;
        totalCost = 0.0;
        paymentStatus = "";
        bookingStatus = "";
    }

    // Function to set booking details
    void setBookingDetails() {
        cout << "... Enter Booking Details:" << endl;
        
        cout << "Guest Name: ";
        getline(cin, guestName);
        
        cout << "Phone Number: ";
        getline(cin, phoneNumber);
        
        cout << "Room Type (Single/Double/Executive): ";
        getline(cin, roomType);
        
        cout << "Room Number: ";
        cin >> roomNumber;
        
        cout << "Number of Nights: ";
        cin >> numberOfNights;
        
        // Clear the input buffer
        cin.ignore();
        
        cout << "Payment Status (Paid/Not Paid): ";
        getline(cin, paymentStatus);
    }

    // Function to validate details
    bool validateDetails() {
        bool valid = true;
        
        // Validate number of nights
        if (numberOfNights <= 0) {
            cout << "ERROR: Number of nights must be greater than zero." << endl;
            valid = false;
        }
        
        // Validate room type
        string roomTypeLower = roomType;
        for (int i = 0; i < roomTypeLower.length(); i++) {
            roomTypeLower[i] = tolower(roomTypeLower[i]);
        }
        
        if (roomTypeLower != "single" && roomTypeLower != "double" && roomTypeLower != "executive") {
            cout << "ERROR: Invalid room type. Must be Single, Double, or Executive." << endl;
            valid = false;
        }
        
        // Validate phone number (basic check)
        if (phoneNumber.length() < 5) {
            cout << "ERROR!!!!!!: Phone number incorrect." << endl;
            valid = false;
        }
        
        return valid;
    }

    // Function to calculate room rate
    void calculateRoomRate() {
        string roomTypeLower = roomType;
        for (int i = 0; i < roomTypeLower.length(); i++) {
            roomTypeLower[i] = tolower(roomTypeLower[i]);
        }
        
        if (roomTypeLower == "single") {
            roomRate = 150.0;
        } else if (roomTypeLower == "double") {
            roomRate = 250.0;
        } else if (roomTypeLower == "executive") {
            roomRate = 400.0;
        } else {
            roomRate = 0.0;
        }
    }

    // Function to calculate total cost
    void calculateTotalCost() {
        totalCost = roomRate * numberOfNights;
    }

    // Function to determine booking status
    void determineBookingStatus() {
        string paymentLower = paymentStatus;
        for (int i = 0; i < paymentLower.length(); i++) {
            paymentLower[i] = tolower(paymentLower[i]);
        }
        
        if (paymentLower == "paid") {
            bookingStatus = "Confirmed Booking";
        } else {
            bookingStatus = "Pending Payment";
        }
    }

    // Function to display booking report
    void displayBookingReport() {
       
        cout << "          BOOKING SUMMARY" << endl;
        cout << "........................................" << endl;
        cout << "Guest Name        : " << guestName << endl;
        cout << "Phone Number      : " << phoneNumber << endl;
        cout << "Room Type         : " << roomType << endl;
        cout << "Room Number       : " << roomNumber << endl;
        cout << "Number of Nights  : " << numberOfNights << endl;
        cout << "Payment Status    : " << paymentStatus << endl;
        cout << "Room Rate         : GHS " << fixed << setprecision(2) << roomRate << endl;
        cout << "Total Cost        : GHS " << fixed << setprecision(2) << totalCost << endl;
        cout << "Booking Status    : " << bookingStatus << endl;
        cout << "END OF REPORT" << endl;
    }

    // Function to save booking report to file
    void saveBookingReport(ofstream& file) {
        file << "----------------------------------------" << endl;
        file << "Guest Name        : " << guestName << endl;
        file << "Phone Number      : " << phoneNumber << endl;
        file << "Room Type         : " << roomType << endl;
        file << "Room Number       : " << roomNumber << endl;
        file << "Number of Nights  : " << numberOfNights << endl;
        file << "Payment Status    : " << paymentStatus << endl;
        file << "Room Rate         : GHS " << fixed << setprecision(2) << roomRate << endl;
        file << "Total Cost        : GHS " << fixed << setprecision(2) << totalCost << endl;
        file << "Booking Status    : " << bookingStatus << endl;
        file << "END OF REPORT" << endl;
    }

    // Getter functions
    string getBookingStatus() const {
        return bookingStatus;
    }

    string getPaymentStatus() const {
        return paymentStatus;
    }
};


void displayWelcome() {
    
    cout << "                                   HOTEL ROOM BOOKING SYSTEM" << endl;
    
    cout << "                             Welcome to the Hotel Booking System!" << endl;
    cout << "                            Enter all booking details as the prompt says!" << endl;
}


void displaySummary(int confirmed, int pending) {
  
    cout << "            FINAL SUMMARY" << endl;
    cout << "..................................." << endl;
    cout << "Confirmed Bookings  : " << confirmed << endl;
    cout << "Pending Bookings    : " << pending << endl;
    cout << "...................................\n" << endl;
}


void saveSummary(ofstream& file, int confirmed, int pending) {
   
    file << "            FINAL SUMMARY" << endl;
    file << "..................................." << endl;
    file << "Confirmed Bookings  : " << confirmed << endl;
    file << "Pending Bookings    : " << pending << endl;
    file << "END OF SUMMARY" << endl;
}


int main() {
    // Display welcome message
    displayWelcome();

    // Ask user for number of bookings
    int numberOfBookings = 0;
    cout << "Enter number of bookings to process: ";
    cin >> numberOfBookings;
    cin.ignore();

    // Validate number of bookings
    if (numberOfBookings <= 0) {
        cout << "ERROR: Number of bookings must be greater than zero." << endl;
        return 1;
    }

    // Vector to store all bookings
    vector<HotelBooking> bookings;

    // Counters
    int confirmedCount = 0;
    int pendingCount = 0;

    // Process each booking 
    for (int i = 0; i < numberOfBookings; i++) {
       
        cout << "            BOOKING " << (i + 1) << endl;
        cout << "................................" << endl;

        HotelBooking booking;
        booking.setBookingDetails();

        if (!booking.validateDetails()) {
            cout << "Skipping this booking due to invalid details." << endl;
            continue;
        }

        booking.calculateRoomRate();
        booking.calculateTotalCost();
        booking.determineBookingStatus();

        booking.displayBookingReport();
        bookings.push_back(booking);

        if (booking.getBookingStatus() == "Confirmed Booking") {
            confirmedCount++;
        } else {
            pendingCount++;
        }
    }

    // Display final summary of the bookings
    displaySummary(confirmedCount, pendingCount);

    // Save report to file
    ofstream outputFile;
    outputFile.open("hotel_booking_report.txt");
    
    if (!outputFile) {
        cout << "ERROR: Unable to create or open hotel_booking_report.txt" << endl;
        return 1;
    }

   
    outputFile << "    HOTEL ROOM BOOKING SYSTEM" << endl;
    outputFile << "          BOOKING REPORT" << endl;
    outputFile << "................................" << endl;
    outputFile << "Total Bookings Processed: " << bookings.size() << endl << endl;

    for (int i = 0; i < bookings.size(); i++) {
        outputFile << "\n--- BOOKING " << (i + 1) << " ---" << endl;
        bookings[i].saveBookingReport(outputFile);
    }

    saveSummary(outputFile, confirmedCount, pendingCount);

    outputFile.close();

    cout << "Report saved as hotel_booking_report.txt" << endl;
    cout << "\nEND OF BOOKING\n" << endl;

    return 0;
}
