# Pseudocode — Hotel Room Booking System

**BEE 208: C++ Programming — Non-Technical Project Question 12**

```
BEGIN
    DISPLAY system title

    INPUT numberOfBookings
    WHILE numberOfBookings <= 0
        DISPLAY "invalid number of bookings"
        INPUT numberOfBookings
    END WHILE

    confirmedCount = 0
    pendingCount = 0

    FOR each booking FROM 1 TO numberOfBookings DO

        INPUT guestName, phoneNumber

        REPEAT
            INPUT roomType
            IF roomType NOT IN {Single, Double, Executive} THEN
                DISPLAY "invalid room type"
            END IF
        UNTIL roomType IS valid

        INPUT roomNumber

        REPEAT
            INPUT numberOfNights
            IF numberOfNights <= 0 THEN
                DISPLAY "invalid number of nights"
            END IF
        UNTIL numberOfNights > 0

        REPEAT
            INPUT paymentStatus
            IF paymentStatus NOT IN {Paid, Not Paid} THEN
                DISPLAY "invalid payment status"
            END IF
        UNTIL paymentStatus IS valid

        DETERMINE roomRate FROM roomType
            Single     -> roomRate = 150
            Double     -> roomRate = 250
            Executive  -> roomRate = 400

        totalCost = roomRate * numberOfNights

        IF paymentStatus = "Paid" THEN
            bookingStatus = "Confirmed Booking"
            confirmedCount = confirmedCount + 1
        ELSE
            bookingStatus = "Pending Payment"
            pendingCount = pendingCount + 1
        END IF

        DISPLAY roomRate, totalCost, bookingStatus
        SAVE booking record to report

    END FOR

    DISPLAY confirmedCount, pendingCount
    SAVE full report to "hotel_booking_report.txt"

END
```
