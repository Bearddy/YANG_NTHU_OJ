#include <stdio.h>
#include <limits.h>
#include <math.h>

int N;
int h[20];
int c[20];
int went[20];
int max_jumps = 0;
int max_energy = 0;
void jump(int S, int T, int pos, int steps, int energies);

int main(){
    int S, T;
    scanf("%d %d %d", &N, &S, &T);
    for(int i = 1; i <= N; i++){
        scanf("%d", &h[i]);
    }

    for(int i = 1; i <= N; i++){
        scanf("%d", &c[i]);
    }
    went[S] = 1;
    jump(S, T, S, 1, 0);
    printf("%d %d\n", max_energy, max_jumps);
    return 0;
}

void jump(int S, int T, int pos, int steps, int energies){
    //printf("stesp : %d, enegergy : %d\n", steps, energies);
    if(pos == T){
        if(energies > max_energy){
            max_energy=energies;
            max_jumps=steps-1;
        }
        else if(energies == max_energy){
            if(steps-1 > max_jumps){
                max_energy=energies;
                max_jumps=steps-1;
            }
        }

    }


    if(pos <= N && pos > 0){
        for(int j = -1; j < 2; j++){
            // printf("now : %d, energy : %d, steps : %d\n", pos, energies, steps);
            // printf("destination : %d, j : %d\n", pos+j, j);
            if(j != 0){
                if(went[pos+j] == 0 && pos+j > 0 && pos+j <= N){
                    //printf("debugdddddddd");
                    went[pos+j] = 1;
                    jump(S, T, pos+j, steps+1, energies+(abs((h[pos] - h[pos+j])*(pos - pos+j))));
                    went[pos+j] = 0;
                }
            }
            else{
                for(int k = 1; k <= N; k++){
                    if(k != pos){
                        //printf("pos: %d, k : %d\n", pos, k);
                        if(c[pos] == c[k] && went[k] == 0){
                            //printf("debug\n");
                            went[k] = 1;
                            jump(S, T, k, steps+1, energies+(abs((h[pos] - h[k])*(pos - k))));
                            went[k] = 0;
                        }
                    }
                }
            }
        }
    }

}


