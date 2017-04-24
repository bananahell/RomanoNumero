#include <iostream>
#include <string>


using namespace std;

bool eValido(string nRomano){
	int i = 0;
	int j = 0;
	int cont = 0;
	bool resul = false;
	bool fim = false;

	/*while(i <= (int) nRomano.length() || !fim){

		if(nRomano[i] == nRomano[j]){

			cont++;
			j++;

			cout << nRomano.length() << " " << nRomano[i] << "(" << i << ")" << " + " << nRomano[j] << "(" << j << ")"  <<  " = " << cont << endl; 

		}else{
			cont = 0;
		}

		if( cont > 3){
			fim = true;
		}

		if(j >= (int) nRomano.length()){
			i++;
			j = 0;
		}else{
			j++;
		}

	}
	if(cont <= 3){
		resul = true;
	}*/

	cout << (int) nRomano.length() << endl;

	while(i <= (int) nRomano.length() && !fim){
		
		//if(i == 0){j = 0;}else{j = i;}
		
		j = 0;

		while(j <= (int) nRomano.length() && !fim){
			
			if(nRomano[i] == nRomano[j] && i != j ){

				cont++;
				cout << nRomano.length() << " " << nRomano[i] << "(" << i << ")" << " + " << nRomano[j] << "(" << j << ")"  <<  " = " << cont << endl; 

			}else{
				cont = 0;
			}

			if(cont > 3){
				fim = true;
			}

			j++;
		}
		i++;
	}
	
	if(!fim && cont <= 3){
		resul = true;
	}

	return resul;
}


int converte(string nRomano){
	int resultado = 0;



	//checa se eh valido


	return resultado;
}




int main(int argc, char const *argv[]){
	string strnro;


	cout << "digite o numero" << endl;
	
	cin >> strnro ;
	
	cout << strnro << endl;

	if(eValido(strnro)){
		cout << "true" << endl;	
	} else{
		cout << "false" << endl;
	}
	return 0;
}