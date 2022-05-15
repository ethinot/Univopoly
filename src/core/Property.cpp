#include "Property.h"

Property::Property(std::string new_name, std::string new_color, std::string new_background, unsigned int new_id, unsigned int new_price, unsigned int new_sell_price, 
					unsigned int new_build_price, unsigned int rent_0, unsigned int rent_1,
					unsigned int rent_2, unsigned int rent_3,
					unsigned int rent_4, unsigned int rent_5){

	name = new_name;
	color = new_color;
	background = new_background;
	id = new_id;
	price = new_price;
	sell_price = new_sell_price;
	build_price = new_build_price;
	rent[0] = rent_0; rent[1] = rent_1;
	rent[2] = rent_2; rent[3] = rent_3;
	rent[4] = rent_4; rent[5] = rent_5;
	rent_count = 0;
	owner = -1;
}

Property::~Property(){}

unsigned int Property::getRent() const{return rent[rent_count];}

unsigned int Property::getBuildPrice() const{return build_price;}

void Property::rentUpgrade(){
	sell_price += 0.3 * build_price;
	rent_count += 1;
}

void Property::emptyProperty(){
	sell_price -= rent_count * (0.3 * build_price);
	rent_count = 0;
}

void Property::testRegProperty(){
	//Création d'un objet propriété
	Property p1("propriété1","blue", "lightblue", 3,100,50,30,30,35,40,45,50,60);

	//test affichage de l'objet
	std::cout<<"Test afficher d'un objet Property"<<std::endl;
	std::cout<<p1<<std::endl;
	
	//getID
	assert(p1.getId() == 3 && 3 == p1.id);
	

	//getColor
	assert(p1.getColor() == "blue" && p1.getColor() == color);

	//getName
	std::string nom = p1.name;
	assert(p1.getName() == "propriété1" && p1.getName() == nom);
	
	//getPrice
	assert(p1.getPrice() == 100 && p1.getPrice() == p1.price);
	
	//getSellPrice
	assert(p1.getSellPrice() == 50 && p1.getSellPrice() == p1.sell_price);
	
	//getBuildPrice
	assert(p1.getBuildPrice() == 30 && p1.getBuildPrice() == p1.build_price);
	
	//getOwner
	assert(p1.getOwner() == -1 && p1.getOwner() == p1.owner);
	
	//bought
	p1.bought(2); // le joeur avec l'id 2 achete le propriété 3
	assert(p1.getOwner() == 2 && p1.owner == 2);
	
	//rentUpgrade
	p1.rentUpgrade();
	unsigned int new_price = 50 + 0.3 * p1.build_price;
	assert(p1.getSellPrice() == new_price);
	assert(p1.rent_count == 1);
	
	//getRent
	assert(p1.getRent() == 35); //prix de loyer avec un batiment
	
	//emptyProperty
	p1.emptyProperty();
	assert(p1.getSellPrice() == 50);
	assert(p1.rent_count == 0);
	
	//sold
	p1.sold(); //vend la propriété p1, le propriétaire passe à -1
	assert(p1.getOwner() == -1 && p1.owner == -1);
}
