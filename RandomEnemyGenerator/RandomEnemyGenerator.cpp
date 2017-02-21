#include <iostream>
#include <string>
#include <ctime>

//using namespace std; es "malo", preferible usar el prefijado std::

enum class EnemyType {zombie, vampire, ghost, witch, MAX}; //Para poder saber la longitud del class enum usamos un truquito, colocar una constante: zombie = 0... MAX = 4

struct Enemy {
	EnemyType type;
	std::string name;
	int health;


	/*Enemy CreateRandomEnemy() {
		Enemy->type = rand();

		return {}
	}*/

	std::string getEnemyTypeString() {  //Correción profesora
		switch (type) {
		case EnemyType::zombie: return "zombie";
		case EnemyType::vampire: return "vampire";
		case EnemyType::ghost: return "ghost";
		case EnemyType::witch: return "witch";
		default: return "";
		}
	}
};

bool operator==(const Enemy &a, const Enemy&b) { //con el & siempre lo pasa por referencia, nunca por copia. Con const nos aseguramos de no modificar el valor de la variable
	return a.name == b.name && a.type == b.type; //comparamos si dos enemigos tienen el mismo nombre y el mismo tipo
}

static Enemy CreateRandomEnemy(){

	static const int MAX_LIFE(500);
	static const std::string NAMES[]{
		"Paco","Miguel","Antonio","Maria","Silvia","Sole"
	};
	return Enemy{  //Devuelve un enemigo con atributos aleatorios
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)), //Aprovechamos el MAX aquí, ya que vale 4
		NAMES[rand() % (sizeof NAMES / sizeof std::string)], //sizeof NAMES / sizeof std::string nos da el numero exacto de elementos que se encuentran en el array NAMES
															 //sizeof NAMES da el numero de bytes que ocupa todo el array NAMES (bytes string * num strings), sizeof std::string es el numero de bytes que ocupa un string
															 //al dividirlo: bytes array NAMES / bytes string = num strings
		rand () % MAX_LIFE
	};
}

int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };//Numero maximo de enemigos que la array permite
	Enemy enemies[MAX_ENEMIES];//Array fija vacia para los enemigos

	{//Inicializacion de cada enemigo en el array
		int i{ 0 };
		while (i < MAX_ENEMIES) {

			enemies[i] = CreateRandomEnemy();
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) {

					--i;
					break;
				};
				j--;
			};
			++i;
		
	}
}
	std::cout << "List of enemies:\n";
	for (auto &enemy : enemies) {

		std::cout << enemy.name <<
			" is a " << enemy.getEnemyTypeString() <<
			" whose life is " << enemy.health << std::endl;
	}
	return 0;
}
