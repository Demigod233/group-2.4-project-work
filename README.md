# BEE208-Hotel-Room-Booking-System

**Accra Technical University — Faculty of Engineering**
**Department of Electrical/Electronic Engineering**
**BEE 208: C++ Programming — Mid-Semester Practical Project Examination**
**Non-Technical Project Question 12: Hotel Room Booking System**

---

## 1. Project Title

Hotel Room Booking System — a C++ console application that records hotel bookings, calculates booking cost, classifies booking status, and generates a saved booking report.

---

## 2. Group Members and Index Numbers

> ⚠️ Replace the placeholders below with your actual group members' names and index numbers before submission.

| # | Name | Index Number | Responsibility |
|---|------|--------------|-----------------|
| 1 | _[Student 1 Name]_ | _[Index Number]_ | Project lead |
| 2 | _[Student 2 Name]_ | _[Index Number]_ | Algorithm writer |
| 3 | _[Student 3 Name]_ | _[Index Number]_ | Pseudocode writer |
| 4 | _[Student 4 Name]_ | _[Index Number]_ | Flowchart designer |
| 5 | _[Student 5 Name]_ | _[Index Number]_ | C++ programmer |
| 6 | _[Student 6 Name]_ | _[Index Number]_ | C++ programmer |
| 7 | _[Student 7 Name]_ | _[Index Number]_ | Testing lead |
| 8 | _[Student 8 Name]_ | _[Index Number]_ | GitHub manager |
| 9 | _[Student 9 Name]_ | _[Index Number]_ | Documentation lead |
| 10 | _[Student 10 Name]_ | _[Index Number]_ | Presentation lead |

---

## 3. Problem Statement

A small hotel needs a basic booking system to record guests, room types, number of nights and payment status. The system should help the receptionist calculate room charges, classify booking status, and save the booking records for future reference. Manual handling of these records can lead to mistakes in room availability, billing, and customer information.

---

## 4. Aim

To develop a C++ Hotel Room Booking System that records guest bookings, calculates total booking cost, checks room booking status, and saves a booking report into a text file.

## 5. Objectives

- Accept guest name, contact number, room type, room number and number of nights.
- Allow users to process more than one hotel booking record.
- Calculate total booking cost based on room type and number of nights.
- Use conditional statements to classify booking status.
- Validate invalid inputs such as negative number of nights or invalid room type.
- Display a clear booking summary for each guest.
- Save all booking records into `hotel_booking_report.txt`.

---

## 6. How the Booking System Works

1. The programme displays a welcome banner and asks the receptionist how many bookings will be processed.
2. For each booking, the programme collects the guest's name, phone number, room type, room number, number of nights, and payment status through a series of prompts.
3. Every input is validated as it is entered:
   - Room type must be **Single**, **Double**, or **Executive** — anything else is rejected and the user is asked again.
   - Number of nights must be a positive whole number — zero or negative values are rejected.
   - Payment status must be **Paid** or **Not Paid**.
4. Once valid data is captured, the programme looks up the correct room rate (Single = GHS 150, Double = GHS 250, Executive = GHS 400) and calculates:

   ```
   Total Cost = Room Rate x Number of Nights
   ```

5. Based on the payment status, the booking is classified as either **Confirmed Booking** (paid) or **Pending Payment** (not paid), and running totals of confirmed/pending bookings are kept.
6. A summary of each booking is displayed on screen as it is processed.
7. After all bookings are entered, the programme displays the total confirmed and pending counts, then writes a complete, formatted report of every booking — plus the summary — to `hotel_booking_report.txt`.

The system is built around a `HotelBooking` class (see `main.cpp`) that encapsulates a single booking record and the operations performed on it: collecting/validating input, calculating the rate and cost, determining the booking status, displaying the record, and writing it to file. A `vector<HotelBooking>` in `main()` stores all the records so the full report can be regenerated and saved after the loop finishes.

---

## 7. Algorithm and Pseudocode

- Full algorithm: see [`algorithm.md`](algorithm.md)
- Full pseudocode: see [`pseudocode.md`](pseudocode.md)

---

## 8. Flowchart

![Hotel Room Booking System Flowchart](flowchart.png)

---

## 9. Screenshots

Sample programme execution (2 bookings — one Double room paid in full, one Single room with pending payment):

![Sample Programme Run](screenshots/sample_run_screenshot.png)

Sample generated report file: see [`hotel_booking_report.txt`](hotel_booking_report.txt)

---

## 10. C++ Concepts Used

| Concept | Where it is used |
|---|---|
| `cin` / `cout` | All user input and screen output |
| Variables & data types (`string`, `int`, `double`) | Storing guest name, room number, nights, rates, costs |
| Arithmetic operators | `totalCost = roomRate * numberOfNights` |
| Conditional statements (`if` / `else`) | Determining room rate, booking status, and validating input |
| Loops (`for`, `while`) | Processing multiple bookings; re-prompting on invalid input |
| Functions | `setBookingDetails()`, `calculateRoomRate()`, `calculateTotalCost()`, `determineBookingStatus()`, `displayBookingReport()`, `saveBookingReport()` |
| Classes and objects | The `HotelBooking` class organises all booking data and behaviour |
| Vectors | `vector<HotelBooking> bookings` stores every processed record |
| File handling (`ofstream`) | Writing `hotel_booking_report.txt` |

---

## 11. Challenges Faced and Solutions

| Challenge | Solution |
|---|---|
| Mixing `cin >>` (extraction) with `getline()` left stray newline characters in the input buffer, causing later prompts to be skipped or read incorrectly. | Used `cin.ignore(numeric_limits<streamsize>::max(), '\n')` at the correct point — immediately after each numeric `cin >>` read that is followed by a `getline()` call — rather than at the start of every booking. |
| Users could type an invalid room type, a negative number of nights, or an unrecognised payment status. | Wrapped each of these inputs in a validation loop (`while`/`REPEAT ... UNTIL`) that re-prompts the user until a valid value is supplied. |
| Needed to store an unknown number of bookings decided at runtime. | Used a `vector<HotelBooking>` instead of a fixed-size array so the collection grows dynamically as bookings are added. |
| Keeping the on-screen summary and the saved file report consistent with each other. | Centralised the calculation logic inside the `HotelBooking` class so both `displayBookingReport()` and `saveBookingReport()` use the same computed values (`roomRate`, `totalCost`, `bookingStatus`). |

---

## 12. Individual Contribution

> ⚠️ Update this table with what each member actually did, and have each member confirm their entry before submission.

| Student | Contribution |
|---|---|
| Student 1 | _Describe specific contribution_ |
| Student 2 | _Describe specific contribution_ |
| Student 3 | _Describe specific contribution_ |
| Student 4 | _Describe specific contribution_ |
| Student 5 | _Describe specific contribution_ |
| Student 6 | _Describe specific contribution_ |
| Student 7 | _Describe specific contribution_ |
| Student 8 | _Describe specific contribution_ |
| Student 9 | _Describe specific contribution_ |
| Student 10 | _Describe specific contribution_ |

---

## 13. Repository Structure

```
BEE208-Hotel-Room-Booking-System/
├── main.cpp
├── README.md
├── algorithm.md
├── pseudocode.md
├── flowchart.png
├── hotel_booking_report.txt
└── screenshots/
    └── sample_run_screenshot.png
```

## 14. How to Compile and Run

```bash
g++ -std=c++17 -Wall -o hotel_booking main.cpp
./hotel_booking
```

The programme will prompt for the number of bookings and the details of each booking, then save the report to `hotel_booking_report.txt` in the same folder.
