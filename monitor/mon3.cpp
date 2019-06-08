#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>

using namespace std;
struct pnode{
	int id;
	int val;
};

pthread_mutex_t mutex;

pnode arr[1001];

bool cmpfunc(int a, int b){
	if(arr[a - 1].val == arr[b - 1].val) return a < b;	
	return arr[a - 1].val > arr[b - 1].val;
}

class monitor {
	vector <int> printer;
		
	public:
		void assign(int id){
			pthread_mutex_lock(&mutex);
			if(printer.size() < 3) {
				printf("\t\tProcess #%d with prirority %d Assigned Printer\n\n", id, arr[id - 1].val);
				printer.push_back(id);
				sort(printer.begin(), printer.end(), cmpfunc);
			}
			else {
				if (arr[printer.back() - 1].val < arr[id - 1].val) {
					printf("\tProcess #%d with priority %d Thrown Out\n\n", printer.back(), arr[printer.back() - 1].val);
					printer.pop_back();
					printf("\t\tProcess #%d with priority %d Assigned Printer\n\n", id, arr[id - 1].val);
					printer.push_back(arr[id - 1].id);
					sort(printer.begin(), printer.end(), cmpfunc);
				} else printf("\tProcess #%d with priority %d will starve\n\n", id, arr[id - 1].val);
			}
			pthread_mutex_unlock(&mutex);
		}
};

monitor m;

void *callThread(void *arg) {
	int id = *(int *)arg;
	printf("\t--------------------------\n\tProcess %d requests printer\n\t--------------------------\n\n", (int)id);
	m.assign(id);
	pthread_exit(NULL);
}

int main() {
	pthread_t process[100001];
	pthread_mutex_init(&mutex, NULL);
	int x = 0;
	while(1) {
		arr[x].id = (x + 1);
		arr[x].val = rand() % 10;
		printf("Process %d assigned priority %d\n\n", arr[x].id, arr[x].val);
		pthread_create(&process[x], NULL, &callThread, &(arr[x].id));
		x++;
		sleep(2);
	}
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	return 0;
}
