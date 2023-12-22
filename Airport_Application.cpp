// This is Airport-Reservation-System Application file.
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

const int Max_record = 100;

// Basic Data Structure
string nameA[Max_record];
string passwordA[Max_record];
string roleA[Max_record];

// Passenger Data arrays
string nameP[Max_record];
string cnicP[Max_record];
string passportNo[Max_record];
string phoneNo[Max_record];
string emailP[Max_record];
string genderP[Max_record];
string departureP[Max_record];
string arrivalP[Max_record];
string trip_typeP[Max_record];
string depart_dateP[Max_record];
string classP[Max_record];
int adultP[Max_record];
int childP[Max_record];
int infantP[Max_record];
int total_seatP[Max_record];
int total[Max_record];
char optionAns[Max_record];

// Function prototypes
void add_user(string name, string password, string role);
void Registrationdataintoarray(string nameP, string cnicP, string passportP, string phoneNo, string emailP, string gender);
void flightdetailPintoarray(string departure, string arrival, string trip_type, string depart_date, string class_p, int adultp, int childp, int infantp, int total_seat);
void forgot();
void clearscreen();
string login_menu();
void seeBooked();
// Count Variables
int entry_count = 0, flight_count = 0, total_count = 0;
string name, password, role;
// This code show "PIA Airline" tag as the Heading.
void header()
{
    system("cls");
    cout << " --------------------------------------------------------------------------------------------------- " << endl;
    cout << "|                                                                                                   |" << endl;
    cout << "|  ||||||||  |||||   |||||||         ||||||||  |||||  ||||||   |       |||||   |       |  |||||||   |" << endl;
    cout << "|  |      |    |     |     |         |      |    |    |    |   |         |     | |     |  |         |" << endl;
    cout << "|  ||||||||    |     |||||||         ||||||||    |    |  ||    |         |     |   |   |  ||||||    |" << endl;
    cout << "|  |           |     |     |         |      |    |    |    |   |         |     |     | |  |         |" << endl;
    cout << "|  |         |||||   |     |         |      |  |||||  |     |  ||||||| |||||   |       |  |||||||   |" << endl;
    cout << " --------------------------------------------------------------------------------------------------- " << endl;
}

// This function show main menu.
int main_menu()
{
    int option;
    cout << "Main Menu  " << endl;
    cout << "-------------------" << endl;
    cout << "Select any one Option.... " << endl;

    cout << "1. Login" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Details" << endl;
    cout << "4. Exit" << endl;

    cout << "Your Option... ";
    cin >> option;
    return option;
}
// This function show login menu part.
string login_menu()
{
    cout << "Main Menu    >   Login" << endl;
    cout << "----------------------" << endl;
    cout << "Enter the Login Details Please." << endl;
    cout << "Enter the name : ";
    cin.get();
    getline(cin, name);
    cout << "Enter the password : ";
    cin >> password;

    for (int i = 0; i < Max_record; i++)
    {
        if (name == nameA[i] && password == passwordA[i])
        {
            return roleA[i];
        }
    }
    forgot();
    return "Exit";
}
// This function has forget Password and reset password option.
void forgot()
{
    int option;
    system("cls");
    header();
    cout << "Main Menu    >   Login   >   Forgot Password" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Seem like you forgot the password\t Don't Worry\n";
    cout << "1. Search Id by UserName\n";
    cout << "2. Go back to Menu\n";
    cout << "Enter your choice...\n";
    cin >> option;
    while (option < 3)
    {
        if (option == 1)
        {

            string nameId;
            cout << " Enter the userID and get Password \n";
            cin.get();
            getline(cin, nameId);

            bool isAccountFound = false;
            for (int i = 0; i < Max_record; i++)
            {
                if (nameId == nameA[i])
                {
                    cout << "Your account is Found\n";
                    cout << "Your password is : " << passwordA[i] << endl;
                    isAccountFound = true;
                    clearscreen();
                    break;
                }
            }
            if (isAccountFound == true)
            {
                break;
            }
            if (isAccountFound == false)
            {
                cout << "Sorry your Account is not Found\n";
                clearscreen();
                header();
                main_menu();
                break;
            }
        }
        else if (option == 2)
        {
            header();
            main_menu();
            break;
        }
        else
        {
            cout << "Wrong Choice! Please Try Again\n";
            break;
        }
    }
}

// This is create_account function
void create_account()
{
    bool flag = true;
    char now;
    string name, password, role;
    cout << "Enter the name : ";
    cin.get();
    getline(cin, name);
    while (flag)
    {
        cout << "Enter the password : ";
        cin >> password;
        // Check if the password length is 8 characters or not.
        if (password.length() < 8)
        {
            cout << "Password must be 8 character long." << endl;
        }
        else
        {
            flag = false;
        }
    }
    cout << "Enter the role (Admin or Passenger) : ";
    cin >> role;

    add_user(name, password, role);
    // cout << "Do you want to login now? (y/n)" << endl;
    // cin.ignore();
    // cin >> now;
    // if (now == 'Y' || now == 'y')
    // {
    //     header();
    //     login_menu();
    // }
    // else
    // {
    //     header();
    //     main_menu();
    // }
}

// This function add any user in the system.
void add_user(string name, string password, string role)
{
    if (total_count < Max_record)
    {
        nameA[total_count] = name;
        passwordA[total_count] = password;
        roleA[total_count] = role;

        if (role == "Passenger")
        {
            entry_count++;
        }
        total_count++;

        cout << endl
             << "User Added Successfully. You can login" << endl;
    }

    else
    {
        cout << "No more users can be added." << endl;
    }
}

// This code has function which show Option 3 which is detail.
void detail()
{
    system("cls");
    header();
    cout << "Main Menu    >   Details" << endl;
    cout << "------------------------" << endl;
    cout << "The PIA Airline application, built in C++, seamlessly integrates user authentication, allowing \nadministrators to manage flights, passengers, and seat allocations, while passengers can \neffortlessly register, book, and manage their flight details with ease. Its intuitive design \nand modular structure enhance the overall user experience for efficient airline management.\n"
         << endl;
    cout << "Developed by : Muhammad Azeem " << endl;
    cout << "Roll no.     : SP23-BSE-031   " << endl;
    cout << "Submitted to : Mr. Muhammad Arslan Sarwar" << endl;
    cout << "Department   : Computer Science" << endl;
}

// This code has function that show Passenger Menu.
int passenger_Menu()
{
    int optionP;
    cout << "Main Menu    >   Login   >   Passenger" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Select any option of the following..." << endl;
    cout << "1. Registration" << endl;
    cout << "2. Enter flight Details" << endl;
    cout << "3. Book from available flight" << endl;
    cout << "4. See booked flight" << endl;
    cout << "5. Cancel a flight" << endl;
    cout << "6. Exit" << endl;

    cout << "Your Option...";
    cin >> optionP;
    return optionP;
}

// This function is to register the passenger detail.
void registrationP()
{
    string name_p, cnic_p, passport_no, phone_no, email_p, gender_p;
    if (entry_count < Max_record)
    {
        cout << "Main Menu  >   Login   >   Passenger   >   Registration" << endl;
        cout << "------------------------" << endl;
        cout << "Fill the following Details Please." << endl;
        cout << "Enter your name : ";
        cin.get();
        getline(cin, name_p);
        cout << "Enter your CNIC : ";
        cin >> cnic_p;
        cout << "Enter your Passport number : ";
        cin >> passport_no;
        cout << "Enter your Phone No. : ";
        cin >> phone_no;
        cout << "Enter your Email Id : ";
        cin >> email_p;
        cout << "Enter your gender : ";
        cin >> gender_p;
        Registrationdataintoarray(name_p, cnic_p, passport_no, phone_no, email_p, gender_p);
    }
    else
    {
        cout << "No more space to enter record." << endl;
    }
}
// This function save the values of registration record into array.
void Registrationdataintoarray(string name_p, string cnic_p, string passport_p, string phone_no, string email_p, string gender_p)
{
    nameP[entry_count] = name_p;
    cnicP[entry_count] = cnic_p;
    passportNo[entry_count] = passport_p;
    phoneNo[entry_count] = phone_no;
    emailP[entry_count] = email_p;
    genderP[entry_count] = gender_p;
}
// This function is used to Enter flight details.
void flightdetailP()
{
    string departure, arrival, trip_type, depart_date, class_p;
    int adultp, childp, infantp, total_seat;
    if (entry_count < Max_record)
    {
        cout << "Main Menu  >   Login   >   Passenger   >   Enter Flight details" << endl;
        cout << "------------------------" << endl;
        cout << "Fill the following Details Please." << endl;
        cout << "Departure from : ";
        cin >> departure;
        cout << "Arrival to : ";
        cin >> arrival;
        cout << "Trip type (Return / One-way) : ";
        cin >> trip_type;
        cout << "Departure Date : ";
        cin >> depart_date;
        cout << "------------Passenger------------" << endl;
        cout << "No. of Passenger(Adult) : ";
        cin >> adultp;
        cout << "No. of Passenger(Child) : ";
        cin >> childp;
        cout << "No. of Passenger(Infant) : ";
        cin >> infantp;
        cout << "------------Class------------" << endl;
        cout << "Enter Class(Business / Economy) : ";
        cin >> class_p;
        total_seat = adultp + childp + infantp;
        flightdetailPintoarray(departure, arrival, trip_type, depart_date, class_p, adultp, childp, infantp, total_seat);
        flight_count++;
        cout << "Flight Details Added Successfully." << endl;
    }
    else
    {
        cout << "No more space to enter record.";
    }
}
// This function save the values of registration record into array.
void flightdetailPintoarray(string departure, string arrival, string trip_type, string depart_date, string class_p, int adultp, int childp, int infantp, int total_seat)
{
    departureP[entry_count] = departure;
    arrivalP[entry_count] = arrival;
    trip_typeP[entry_count] = trip_type;
    depart_dateP[entry_count] = depart_date;
    classP[entry_count] = class_p;
    adultP[entry_count] = adultp;
    childP[entry_count] = childp;
    infantP[entry_count] = infantp;
    total_seatP[entry_count] = total_seat;
}
// This function booked the flight.
char bookflightP()
{
    string passengerName;
    cout << "Main Menu    >   Login   >   Passenger   >   Book from available flight" << endl;
    cout << "-------------------------" << endl;
    cout << "Enter your name : ";
    cin.get();
    getline(cin, passengerName);
    cout << "You want to book flight, with the previous details? (y/n)" << endl;
    cin >> optionAns[entry_count];
    if (passengerName == nameP[entry_count])
    {
        cout << "Your flight is booked successfully. You can now see your booked Ticket." << endl;
    }
    else
    {
        cout << "Your name is not found in the record. Please register yourself first." << endl;
    }
    return optionAns[entry_count];
}
// This function show booked flights
void seeBooked()
{
    string nameId;
    cout << "Enter the Name to see the booked Ticket \n";
    cin.get();
    getline(cin, nameId);

    bool isAccountFound = false;
    for (int i = 0; i < Max_record; i++)
    {
        if (nameId == nameP[i])
        {
            isAccountFound = true;
            if (optionAns[entry_count] == 'Y' || optionAns[entry_count] == 'y')
            {
                cout << endl;
                cout << "Your Flight is booked successfully." << endl;
                cout << "Your Ticket detail is : " << endl;
                cout << "From :             " << departureP[entry_count] << endl;
                cout << "To :               " << arrivalP[entry_count] << endl;
                cout << "At :               " << depart_dateP[entry_count] << endl;
                cout << "Trip type :        " << trip_typeP[entry_count] << endl;
                cout << "Depart Date :      " << depart_dateP[entry_count] << endl;
                cout << "Adult Passenger :  " << adultP[entry_count] << endl;
                cout << "Child Passenger :  " << childP[entry_count] << endl;
                cout << "Infant Passenger : " << infantP[entry_count] << endl;
                cout << "Total Seats :      " << total_seatP[entry_count] << endl;
                cout << endl;
                cout << "---------Expenditures---------" << endl;
                cout << "No of Passenger (Adult) ($600): " << adultP[entry_count] << endl;
                cout << "No of Passenger (Child) ($400): " << childP[entry_count] << endl;
                cout << "No of Passenger (Infant) ($0): " << infantP[entry_count] << endl;
                cout << endl;
                total[entry_count] = (adultP[entry_count] * 600) + (childP[entry_count] * 400);
                if (classP[i] == "Business" || classP[entry_count] == "business")
                {
                    total[entry_count] = total[entry_count] + 400;
                }
                cout << "If your flight is Business class then you have to pay 400$ more." << endl;
                cout << "Your Total Expenditure is : " << total[entry_count] << "$" << endl;
            }
            else
            {
                cout << "You have not booked any flight yet." << endl;
            }
            break; // Exit the loop once a match is found
        }
    }
    if (!isAccountFound)
    {
        cout << "Your name is not found in the record. Please register yourself first." << endl;
    }
}
// This function is used to cancel the flight.
void cancelFlight()
{
    char cancel;
    bool isFlightFound = false;
    for (int i = 0; i < Max_record; i++)
    {
        if (name == nameA[i])
        {
            cout << "Your Ticket detail is : " << endl;
            cout << "From :             " << departureP[entry_count] << endl;
            cout << "To :               " << arrivalP[entry_count] << endl;
            cout << "At :               " << depart_dateP[entry_count] << endl;
            cout << "Trip type :        " << trip_typeP[entry_count] << endl;
            cout << "Depart Date :      " << depart_dateP[entry_count] << endl;
            cout << "Total Seats :      " << total_seatP[entry_count] << endl;
            cout << "Your Total Expenditure is : " << total[entry_count] << "$" << endl;
            cout << endl;
            cout << "Do you want to cancel your flight? (y/n) : ";
            cin >> cancel;
            if (cancel == 'y' || cancel == 'Y')
            {
                optionAns[entry_count] = 0;
                isFlightFound = true;
            }
            if (isFlightFound == false)
            {
                cout << "Your Flight was not booked." << endl;
            }
            else
            {
                cout << "Your flight is cancelled." << endl;
            }
        }
    }
}

// This code clear the screen.
void clearscreen()
{
    // let user see result of their choice, clear screen and present menu again
    cout << "Press any key to continue : ";
    getch();       // get a key press from user
    system("cls"); // Clear the screen
}
// Here starts our main function.
int main()
{
    string who = " ";
    int option = 0;
    int optionP = 0;

    while (option < 4)
    {
        header();
        option = main_menu();
        // Login Menu starts from here.
        if (option == 1)
        {

            header();
            who = login_menu();

            // Passenger Menu start
            if (who == "Passenger")
            {
                optionP = 0;
                while (optionP < 6)
                {
                    header();
                    optionP = passenger_Menu();
                    // Passenger Menu Options.
                    if (optionP == 1)
                    {
                        header();
                        registrationP();
                        clearscreen();
                    }
                    // This option is to enter flight details.
                    else if (optionP == 2)
                    {
                        header();
                        flightdetailP();
                        clearscreen();
                    }
                    // This option is to book flight.
                    else if (optionP == 3)
                    {
                        header();
                        bookflightP();
                        clearscreen();
                    }
                    // This option is to see booked flight.
                    else if (optionP == 4)
                    {
                        header();
                        seeBooked();
                        clearscreen();
                    }
                    // This option is to cancel flight.
                    else if (optionP == 5)
                    {
                        header();
                        cancelFlight();
                        clearscreen();
                    }
                    // This option is to exit from Passenger menu.
                    else if (optionP == 6)
                    {
                        break; // Break the loop and return to the Main Menu.
                    }
                }
            }
            else if (who == "Admin")
            {
                cout << "The application currently does not support admin functionality." << endl;
                clearscreen();
            }
        }
        // This option is to create account.
        else if (option == 2)
        {
            system("cls");
            header();
            cout << "Main Menu    >   Sign up" << endl;
            cout << "------------------------" << endl;
            create_account();
            clearscreen();
        }
        // This option is to show details about the Application.
        else if (option == 3)
        {
            detail();
            clearscreen();
        }
        // This option is to exit from the application.
        else if (option == 4)
        {
            cout << "Thank you for using our application." << endl;
            cout << "See You Soon..." << endl;
            break;
        }
    }
}