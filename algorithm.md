# Algorithm — Hotel Room Booking System

**BEE 208: C++ Programming — Non-Technical Project Question 12**

1. Start the programme.
2. Display the Hotel Room Booking System title.
3. Ask the user to enter the number of booking records.
4. For each booking, from 1 to the number of bookings:
   1. Input guest name, phone number, room type, room number, number of nights and payment status.
   2. Validate the room type (must be Single, Double or Executive) and the number of nights (must be greater than zero). If invalid, prompt the user again until valid data is entered.
   3. Determine the room rate based on the room type:
      - Single → GHS 150 per night
      - Double → GHS 250 per night
      - Executive → GHS 400 per night
   4. Calculate the total cost: `Total Cost = Room Rate x Number of Nights`.
   5. Determine the booking status based on payment status:
      - If payment status is "Paid" → Booking Status = "Confirmed Booking"
      - Otherwise → Booking Status = "Pending Payment"
   6. Display the booking summary (room rate, total cost, booking status) on the screen.
   7. Save the booking record to the report file.
   8. Update the count of confirmed bookings or pending bookings.
5. After all bookings have been processed, display the total number of confirmed bookings and the total number of pending bookings.
6. Save the complete booking report, including all individual records and the summary counts, to `hotel_booking_report.txt`.
7. End the programme.
