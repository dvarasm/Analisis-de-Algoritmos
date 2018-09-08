#include <iostream>
#include <vector>

using namespace std;

int main(){
	int caso = 0;
	while (true){
		caso++;
		int ciudades, vuelos;
		cin >> ciudades;
		cin >> vuelos;
		if ((ciudades == 0) && (vuelos == 0)){
			break;
		}
        // Step 1: Allocation
		vector<vector<vector<int> > > horarios_vuelos;
		      
		horarios_vuelos.resize(ciudades);
		cout << "size1:" << horarios_vuelos.size()<<endl;
		for (int src = 0; src < ciudades; src++){
			horarios_vuelos[src].resize(ciudades);
		}
		cout << "size2:" << horarios_vuelos[0].size()<<endl;
		cout << "size2:" << horarios_vuelos[1].size()<<endl;
		cout << "size2:" << horarios_vuelos[2].size()<<endl;
        // Step 2: Read inputs
		for (int src = 0; src < ciudades; src++){
			for (int dst = 0; dst < ciudades; dst++){
				if (src != dst){
					int periodo;
					cin >> periodo;
					horarios_vuelos[src][dst].resize(periodo);
					for (int p = 0; p < periodo; p++){
						cin >> horarios_vuelos[src][dst][p];
						printf("datos[%d][%d][%d] = %d\n",src,dst,p,horarios_vuelos[src][dst][p]);
					}
				}
			}
		}

        // Step 3: Bellman-ford
		vector<int> old_cost;
		vector<bool> old_reachable;
		vector<int> new_cost;
		vector<bool> new_reachable;
		old_cost.resize(ciudades);
		new_cost.resize(ciudades);
		old_reachable.resize(ciudades);
		new_reachable.resize(ciudades);

        // Step 3.1: Initialize old_cost to be 0, only cities 0 is reachable
		for (int c = 0; c < ciudades; c++){
			old_cost[c] = 0;
			old_reachable[c] = (c == 0);
		}
        
        // Step 3.2: Relaxation
		for (int k = 0; k < vuelos; k++){
			for (int c = 0; c < ciudades; c++){
				new_reachable[c] = false;
			}
			for (int dst = 0; dst < ciudades; dst++){
				bool first = true;
				for (int src = 0; src < ciudades; src++){
					if (old_reachable[src] && src != dst){
						int periodo = horarios_vuelos[src][dst].size();
						printf("periodo[%d][%d] = %d\n",src,dst,horarios_vuelos[src][dst].size());
						int day_in_period = k % periodo;
						printf("day_in_period = %d\n",day_in_period);
						int cost = horarios_vuelos[src][dst][day_in_period];
						printf("cost[%d][%d][%d] = %d\n",src,dst,day_in_period,cost);
						if (cost > 0){
							new_reachable[dst] = true;
							if (first){
								new_cost[dst] = old_cost[src] + cost;
								first = false;
							}
							else{
								new_cost[dst] = min(new_cost[dst], old_cost[src] + cost);
							}
						}
					}
				}
			}
            // Copy new to old
			for (int c = 0; c < ciudades; c++){
				old_cost[c] = new_cost[c];
				old_reachable[c] = new_reachable[c];
			}
/*	
            cout << "On day " << k << " we have: ";
            for (int c = 0; c < ciudades; c++)
            {
                if (old_reachable[c])
                {
                    cout << old_cost[c] << " ";
                }
                else
                {
                    cout << "X" << " ";
                }
            }
            cout << endl;
*/
        	}

        // Step 4: Output
		cout << "Scenario #" << caso << endl;
		if (old_reachable[ciudades - 1]){
			cout << "The best flight costs " << old_cost[ciudades - 1] << endl;
		}
		else{
			cout << "No flight possible." << endl;
		}
		//cout << endl;
	}
	return 0;
}
