#include <iostream>

class Car{
	private:
		std::string name, model;
		int max_speed;
	public:
		Car(){
			name = "Mercedes";
			model = "C-class";
			max_speed = 250;
		}
		Car(std::string name, std::string model, int max_speed){
			this->name = name;
			this->model = model;
			this->max_speed = max_speed;
		}

		std::string get_name(){
			return name;
		}
};

class Parking{
	private:
		bool is_jeep;
		int price;
		int parking_places;		
	public:
		Parking(){
			price = 0;
			parking_places = 0;
		}
		Parking(int price, int parking_places){
			this->price = price;
			this->parking_places = parking_places;
		}
		void Reserving_place(Car* c){
			if(parking_places >= 100)
			{
				std::cerr << "Parking places are full";
				abort();
			}
			if(c->get_name() == "Jeep"){
				price += 500;
			}
			else{
				price += 200;
			}
			parking_places++;
		}
		int get_parking_places(){
			return parking_places;
		}
};

int main(){
	Car* Mercedes = new Car;
	Car* Jeep = new Car("Jeep","Wrangler",122);

	Parking* parking_obj1 = new Parking;
	Parking* parking_obj2 = new Parking(4700,52);

	std::cout << "Parking places before\n" << parking_obj1->get_parking_places() << std::endl << parking_obj2->get_parking_places() << std::endl;
	
	parking_obj1->Reserving_place(Mercedes);
	parking_obj2->Reserving_place(Jeep);

	std::cout << "Parking places after\n" << parking_obj1->get_parking_places() << std::endl << parking_obj2->get_parking_places() << std::endl;

	delete Mercedes;
	Mercedes = nullptr;
	delete Jeep;
	Jeep = nullptr;

	return 0;
}
