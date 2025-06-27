//including header files
#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // for file handling
#include <sstream>  // For istringstream

using namespace std;
//car related attributes and functions
class Car{
    string carID;
    string brand;
    string model;
    int manufacturingYear;
    float rentalRate;
    bool isAvailable;
public:
    Car(){//constructor
        carID="0";
        brand="none";
        model="none";
        manufacturingYear=0;
        rentalRate=0.0f;
        isAvailable=true;
    }
    Car(string id,string Brand,string Model,int year,float rent,bool available){//parameterized constructor
        carID=id;
        brand=Brand;
        model=Model;
        manufacturingYear=year;
        rentalRate=rent;
        isAvailable=available;
    }
    bool checkAvailability() const {//imp constant
        return isAvailable;//getter thats why const
    }//checks whether a car is available
    void setAvailability(bool status) {
        isAvailable = status;//setter
    }
    string getCarID() const {
        return carID;//getter
    }
    string getBrand() const {
        return brand;//getter
    }
    string getModel() const {
        return model;//getter
    }
    int getManufacturingYear()const{
        return manufacturingYear;//getter
    }
    float getRentalRate() const {
        return rentalRate;//getter
    }
    void displayInfo() const {

        cout<<"car id is: "<<carID<<endl;
        cout<<"car brand is: "<<brand<<endl;
        cout<<"car model is: "<<model<<endl;
        cout<<"car manufacturing year is: "<<manufacturingYear<<endl;
        cout<<"car rent is rupees: "<<rentalRate<<endl;
    }
};
//customer related attributes and functions
class Customer{
   string customerID;
   string name;
   string phoneNumber;
   vector<string> rentedCars;// (or one car at a time)
public:
    Customer(string CustomerID,string Name,string PhoneNumber){
        customerID=CustomerID;
        name=Name;
        phoneNumber=PhoneNumber;
    }
    void addRentedCar(string carID){
        rentedCars.push_back(carID);
    }//adds rented car to customer's list of cars
    void removeRentedCar(string carID){
        /*int index;
        for(int i=0;i<rentedCars.size();i++){
            if(rentedCars[i]==carID){
                index=i;
            }
            else{
                index=-1;
            }
        }
        if(index!=-1){
            rentedCars.erase(index);
        }*///incorrect
        for (int i = 0; i < rentedCars.size(); i++) {
        if (rentedCars[i] == carID) {
            rentedCars.erase(rentedCars.begin() + i);
            break;
        }
    }
    }//removes car from customer's list
    string getCustomerID() const {
        return customerID;
    }
    string getName()const{
        return name;
    }
    string getPhoneNumber()const{
        return phoneNumber;
    }
    const vector<string>& getRentedCars() const {
        return rentedCars;
    }
    bool hasRentedCar(const string& carID) const {//The function is const, meaning it won’t modify the object (read-only).
        for (const auto& id : rentedCars)
             if (id == carID) return true;
             return false;
        }
    //checks whether the customer has a particular car, rented
    void displayProfile()const{//imp
       cout<<"Customer name: "<<name<<endl;
       cout<<"id: "<<customerID<<endl;
       cout<<"contact no. : "<<phoneNumber<<endl;
       for(int i=0;i<rentedCars.size();i++){
        cout<<"rented cars are: "<<rentedCars[i]<<", ";
       }
       cout<<endl;
    }
};
//rental information
class Rental{
    float rentalrate;
    string customerID;
    string carID;
    string rentDate;
    string returnDate;
    float totalCost;
public:
    Rental(float Rentalrate,string CustomerID,string CarID,string RentDate,string ReturnDate){
        rentalrate=Rentalrate;
        customerID=CustomerID;
        carID=CarID;
        rentDate=RentDate;
        returnDate=ReturnDate;
    }
    string getCustomerID() const {
        return customerID;
    }
    string getCarID() const {
        return carID;
    }
    string getRentDate() const {
        return rentDate;
    }
    string getReturnDate() const {
        return returnDate;
    }
    float getRentalRate() const {
        return rentalrate;
    }
    void setTotalCost(float cost) {
        totalCost = cost;
    }//initialize total cost
    float getTotalCost() const {
        return totalCost;
    }
    float calculateCost(int days){
        totalCost=rentalrate*days;
        return totalCost;
    }
    void displayRentalInfo()const{
        cout<<"Rental Record:"<<endl;
        cout<<"Customer ID: "<<customerID<<endl;
        cout<<"Car ID: "<<carID<<endl;
        cout<<"Rental rate: "<<rentalrate<<endl;
        cout<<"Rent date: "<<rentDate<<endl;
        cout<<"Return date: "<<returnDate<<endl;
        cout<<"Total Cost: "<<totalCost<<endl;
    }
};
//general functions

//adds a car to the cars list
 void addCar(vector<Car> &carList){
     cout<<"Enter the car details in following order: car id,brand, model,manufacturing year, rent"<<endl;
     string ID, BRAND, MODEL;
     int ManufacturingYear;
     float Rent;
     cin>>ID>>BRAND>>MODEL>>ManufacturingYear>>Rent;
     Car c(ID,BRAND,MODEL,ManufacturingYear,Rent,true);
     carList.push_back(c);
}
//shows a list of cars with their features
void viewAllCars(const vector<Car> &carList){//imp const
    for(int i=0;i<carList.size();i++){
            carList[i].displayInfo();
            cout << "------------------\n";
    }
}
//registers a customer in the customers list
 void registerCustomer(vector<Customer> &customerList){
    cout<<"Enter your details in following order: customer id, name, contact number"<<endl;
    string ID, NAME, PHno;
    cin>>ID>>NAME>>PHno;
    Customer cust(ID,NAME,PHno);
    customerList.push_back(cust);
}
//shows a list of customers
 void viewAllCustomers(const vector<Customer> &customerList){//imp const
    for(int i=0;i<customerList.size();i++){
            customerList[i].displayProfile();
            cout << "------------------\n";
    }
}
//helps a customer to rent a car
void rentCar(vector<Car> &carList, vector<Customer> &customerList, vector<Rental> &rentalRecords){
    string customerId, carId;
    int customerIndex=-1, carIndex=-1;
    cout<<"Enter the details in following order: customer id, car id"<<endl;
    cin>>customerId>>carId;
     for (int i = 0; i < customerList.size(); i++) {
        if (customerList[i].getCustomerID() == customerId) {//wrong pvt access customerList[i].customerID ==customerId
            customerIndex=i;
            break;
        }
    }
    if (customerIndex == -1) {
        cout << "Customer not found.\n";
        return;
    }
    for (int i = 0; i < carList.size(); i++) {
        if (carList[i].getCarID() == carId ) {//carList[i].carID ==carId
            carIndex=i;
            break;
        }
    }
    if (carIndex == -1) {
        cout << "Car not found.\n";
        return;
    }
    if(carList[carIndex].checkAvailability()){

             string rentDate, returnDate;
             int rentalDays;
             cout << "Enter rent date (e.g., 2025-06-27): ";
             cin >> rentDate;
             cout << "Enter return date (e.g., 2025-06-30): ";
             cin >> returnDate;
             cout << "Enter number of rental days: ";
             cin >> rentalDays;
             float rate = carList[carIndex].getRentalRate();
             Rental r(rate, customerId, carId, rentDate, returnDate);//object creation
             r.calculateCost(rentalDays);

             // Update system
             carList[carIndex].setAvailability(false);
             customerList[customerIndex].addRentedCar(carId);
             rentalRecords.push_back(r);  // Log the rental

            cout << "Car rented successfully!\n";
            /*customerList[customerIndex].rentedCars.push_back(carId);
    */ // not allowed because of private members
    }
    else {
        cout << "Car is not available for rent.\n";
    }
}
//shows all rental records
void viewAllRentalRecords(const vector<Rental>& rentalRecords) {
    if (rentalRecords.empty()) {
        cout << "No rental records found.\n";
        return;
    }
    for (const Rental& r : rentalRecords) {//class type of variable
        r.displayRentalInfo();
        cout << "------------------\n";
    }
}
//helps a customer to return a car
void returnCar(vector<Car> &carList, vector<Customer> &customerList){
    string customerId, carId;
    int customerIndex=-1, carIndex=-1;
    cout<<"Enter the details in following order: customer id, car id"<<endl;
    cin>>customerId>>carId;
     for (int i = 0; i < customerList.size(); i++) {
        if (customerList[i].getCustomerID() == customerId) {//wrong pvt access customerList[i].customerID ==customerId
            customerIndex=i;
            break;
        }
    }
    if (customerIndex == -1) {
        cout << "Customer not found.\n";
        return;
    }
    for (int i = 0; i < carList.size(); i++) {
        if (carList[i].getCarID() == carId ) {//carList[i].carID ==carId
            carIndex=i;
            break;
        }
    }
    if (carIndex == -1) {
        cout << "Car not found.\n";
        return;
    }
    /*vector<string> rentedcars;
    rentedcars=customerList[customerIndex].getRentedCars();
    for(int i=0;i<rentedcars.size();i++){
        if(rentedcars[i]==carId){
                carList[carIndex].setAvailability(true);
                customerList[customerIndex].removeRentedCar(carId);
                cout<<"car has been successfully returned"<<endl;
                return;//or break; imp step
                //If the same car ID appears more than once (accidentally), it will try to remove it multiple times.
                // After the first removal, the vector size changes and leads to unexpected behavior.
        }
    }*///better method:
     if (customerList[customerIndex].hasRentedCar(carId)) {
        customerList[customerIndex].removeRentedCar(carId);
        carList[carIndex].setAvailability(true);
        cout << "Car has been successfully returned.\n";
    } else {
        cout << "This car was not rented by this customer.\n";
    }
}
//stores cars data in file
void saveCarsToFile(const vector<Car>& carList) {
    ofstream carfile("cars.txt");  // Creates or overwrites file

    if (!carfile) {
        cout << "Could not open cars.txt for writing.\n";
        return;
    }

    for (const Car& c : carList) {
        // Save all car attributes in a line
        carfile << c.getCarID() << " "
            << c.getBrand() << " "
            << c.getModel() << " "
            << c.getManufacturingYear() << " "
            << c.getRentalRate() << " "
            << c.checkAvailability() << "\n";
    }

    carfile.close();  // Always close
}
//stores customers data in file
void saveCustomersToFile(const vector<Customer>& customerList) {
    ofstream out("customers.txt");//can also use customerFile instead of out

    if (!out) {
        cout << "Could not open customers.txt for writing.\n";
        return;
    }

    for (const Customer& c : customerList) {
        out << c.getCustomerID() << " "
            << c.getName() << " "
            << c.getPhoneNumber() << "\n";
        const vector<string>& rented = c.getRentedCars();
        for (const string& id : rented) {
            out << id << " ";  // All rented car IDs in one line
        }
        out << "\n";  // Separate each customer
    }

    out.close();
}
////stores rental data in file
void saveRentalsToFile(const vector<Rental>& rentalList) {
    ofstream out("rentals.txt");

    if (!out) {
        cout << "Could not open rentals.txt for writing.\n";
        return;
    }

    for (const Rental& r : rentalList) {
        out << r.getCustomerID() << " "
            << r.getCarID() << " "
            << r.getRentalRate() << " "
            << r.getRentDate() << " "
            << r.getReturnDate() << " "
            << r.getTotalCost() << "\n";
    }

    out.close();
}
//loads cars data from file
void loadCarsFromFile(vector<Car>& carList) {
    ifstream in("cars.txt");

    if (!in) {
        cout << "cars.txt not found. Starting with empty list.\n";
        return;
    }

    string id, brand, model;
    int year;
    float rate;
    bool available;

    while (in >> id >> brand >> model >> year >> rate >> available) {
        carList.emplace_back(id, brand, model, year, rate, available);
    }

    in.close();
}
//loads customers data from file
void loadCustomersFromFile(vector<Customer>& customerList) {
    ifstream in("customers.txt");

    if (!in) {
        cout << "customers.txt not found. Starting with empty customer list.\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string id, name, phone;
        iss >> id >> name >> phone;

        Customer c(id, name, phone);

        // Get next line: rented cars
        if (getline(in, line)) {
            istringstream carStream(line);
            string carID;
            while (carStream >> carID) {
                c.addRentedCar(carID);
            }
        }

        customerList.push_back(c);
    }

    in.close();
}
//loads rental data from file
void loadRentalsFromFile(vector<Rental>& rentalList) {
    ifstream in("rentals.txt");

    if (!in) {
        cout << "rentals.txt not found. Starting with empty rental list.\n";
        return;
    }

    string customerID, carID, rentDate, returnDate;
    float rentalRate, totalCost;

    while (in >> customerID >> carID >> rentalRate >> rentDate >> returnDate >> totalCost) {
        Rental r(rentalRate, customerID, carID, rentDate, returnDate);
        r.setTotalCost(totalCost); // properly set the cost
        rentalList.push_back(r);
    }

    in.close();
}
//main() function
int main()
{
    vector<Car> carList;
    vector<Customer> customerList;
    vector<Rental> rentalRecords;
    int choice;

    // Load data at startup
    loadCarsFromFile(carList);
    loadCustomersFromFile(customerList);
    loadRentalsFromFile(rentalRecords);

    do {
        cout << "\n--- Car Rental System ---\n";
        cout << "1. Add Car\n";
        cout << "2. View All Cars\n";
        cout << "3. Register Customer\n";
        cout << "4. View All Customers\n";
        cout << "5. Rent a Car\n";
        cout << "6. Return a Car\n";
        cout << "7. View All Rental Records\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addCar(carList);
                break;
            case 2:
                viewAllCars(carList);
                break;
            case 3:
                registerCustomer(customerList);
                break;
            case 4:
                viewAllCustomers(customerList);
                break;
            case 5:
                rentCar(carList, customerList, rentalRecords);
                break;
            case 6:
                returnCar(carList, customerList);
                break;
            case 7:
                viewAllRentalRecords(rentalRecords);
                break;
            case 8:
                saveCarsToFile(carList);
                saveCustomersToFile(customerList);
                saveRentalsToFile(rentalRecords);
                cout << "Data saved. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 8);

    return 0;
}
