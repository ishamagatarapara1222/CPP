#include<iostream>
#include<vector>
using namespace std;

//base class
class Vehicle{
	protected:
		int vehicleID;
		string manufacturer;
		string model;
		int year;
		
	public:
		static int totalVehicles;
		
		Vehicle(int id, string mfg, string mdl, int yr){
			vehicleID = id;
			manufacturer = mfg;
			model = mdl;
			year = yr;
			totalVehicles++;
		}
		
		~Vehicle(){
			totalVehicles--;
		}
		
		int getID(){
			return vehicleID;
		}
		
		virtual void display(){
			cout << "ID: " << vehicleID << endl;
			cout << "Manufacturer: " << manufacturer <<endl;
			cout << "Model: " << model << endl;
			cout << "Year:" << year << endl;
		}
};

int Vehicle::totalVehicles = 0;

//single inheritance
class Car : public Vehicle{
	protected:
		string fuelType;
		
	public:
		Car(int id, string mfg, string mdl, int yr, string fuel)
		:Vehicle(id, mfg, mdl, yr){
			fuelType = fuel;
		}
		
	   void	display(){
	   	Vehicle :: display();
	   	cout <<"Fuel Type: " << fuelType << endl;
	   }
};

//multilevel inheritance
class ElectricCar : public Car{
	protected:
		int batteryCapacity;
		
	public:
		ElectricCar(int id, string mfg, string mdl, int yr, int battery)
		:Car(id, mfg ,mdl, yr, "Electric"){
			batteryCapacity = battery;
		}
		
		void display(){
			Car::display();
			cout << "Battery: " << batteryCapacity << "kwh" << endl;
		}
};

//multilevel from Electric Car
class SportsCar : public ElectricCar{
	int topSpeed;
	
	public:
		SportsCar(int id, string mfg, string mdl, int yr, int battery, int speed)
		:ElectricCar(id, mfg, mdl, yr, battery){
			topSpeed = speed;
		}
		
		void display(){
			ElectricCar::display();
			cout << "Top Speed: " << topSpeed << " km/h \n";
		}
};

//hierarchical
class SUV : public Car{
	public:
		SUV(int id, string mfg, string mdl, int yr, string fuel)
		:Car(id, mfg, mdl, yr, fuel){}
		
		void display(){
			Car::display();
			cout << "Type: SUV \n";
		}
};

class Sedan : public Car{
	public:
		Sedan(int id, string mfg, string mdl, int yr, string fuel)
		:Car(id, mfg, mdl, yr, fuel){}
		
		void display(){
			Car::display();
			cout << "Type: Sedan\n";
		}
};

//aircraft class (for multiple inheritance)
class Aircraft {
	protected:
		int altitude;
		
	public:
		Aircraft(int alt){
			altitude = alt;
		}
		
		void showAltitude(){
			cout << "Max Altitude: " << altitude << "ft\n";
		}
};

//multiple inheritance (car + aircraft)
class FlyingCar : public Car, public Aircraft{
	public:
		FlyingCar(int id, string mfg, string mdl, int yr, string fuel, int alt)
		:Car(id, mfg, mdl, yr, fuel), Aircraft(alt){}
		
		void display(){
			Car::display();
			showAltitude();
			cout << "Type: Flying Car \n";
		}
};

//registry
class VehicleRegistry{
	
	vector<Vehicle*> list;
	
	public:
		void addVehicle(Vehicle* v){
			list.push_back(v);
		}
		
		void displayAll(){
			for(int i=0; i<list.size(); i++){
				cout << "\n-------Vehicle " << i+1 << "------\n";
				list[i]->display();
			}
		}
		
		void searchByID(int id){
			bool found =  false;
			for(int i=0; i < list.size(); i++){
				if(list[i]->getID() == id){
					list[i]->display();
					found = true;
					break;
				}
			}
			
			if(!found)
				cout << "Vehilcle not Found!\n";
		}
};

//main
int main(){
	
	VehicleRegistry vr;
	int choice;
	
	do{
		cout << "\n====Vehicle Registry====\n";
		cout << "1. Add Car\n";
		cout << "2. Add Electric Car\n";
		cout << "3. Add Sports Car\n";
		cout << "4. Add SUV\n";
		cout << "5. Add Sedan\n";
		cout << "6. Add Flying Car\n";
		cout << "7. Display All\n";
		cout << "8. Search By ID\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		int id, year, battery, speed, altitude;
		string mfg, mdl, fuel;
		
		switch(choice){
			
			case 1:
				cout << "Enter ID, Manufacturer, Model, Year, Fuel: \n";
				cin >> id >> mfg >> mdl >> year >> fuel;
				vr.addVehicle(new Car(id, mfg, mdl, year, fuel));
				break;
				
			case 2:
				cout << "Enter ID, Manufacturer, Model, Year, Battery: \n";
				cin >> id >> mfg >> mdl >> year >> battery;
				vr.addVehicle(new ElectricCar(id, mfg, mdl, year, battery));
				break;
				
			case 3:
				cout <<"Enter ID, Manufacturer, Model, Year, Battery, Speed: \n";
				cin >> id >> mfg >> mdl >> year >> battery >> speed;
				vr.addVehicle(new SportsCar(id, mfg, mdl, year, battery, speed));
				break;
				
			case 4:
				cout << "Enter ID, Manufacturer, Model, Year, Fuel:\n";
				cin >> id >> mfg >> mdl >> year >> fuel;
            	vr.addVehicle(new SUV(id, mfg, mdl, year, fuel));
            	break;
            	
            case 5:
            	cout << "Enter ID, Manufacturer, Model, Year, Fuel:\n";
            	cin >> id >> mfg >> mdl >> year >> fuel;
				vr.addVehicle(new Sedan(id, mfg, mdl, year, fuel));
				break;
				
			case 6:
				cout << "Enter ID, Manufacturer, Model, Year, Fuel, Altitude: \n";
				cin >> id >> mfg >> mdl >> year >> fuel >> altitude;
				vr.addVehicle(new FlyingCar(id, mfg, mdl, year, fuel, altitude));
				break;
				
			case 7:
				vr.displayAll();
				cout << "Total Vehicles: " << Vehicle::totalVehicles << endl;
				break;
				
			case 8:
				cout << "Enter ID: ";
				cin >> id;
				vr.searchByID(id);
				break;
		} 
			
	}while( choice =! 0);
	
	return 0;
	 
}





























