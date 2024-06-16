#include <stdio.h>
#include <math.h>
#include <vector.h>
#include <string.h>




#define b 100    // Impact parameter in fm
void nucleus::DistributeNucleon(const float& x_offset);

class nucleus{
    private:

    public:
    
    void DefineShape();
    void DistributeNucleon();
}
int main(){
    generate_collisions(1000, b);
}



void generate_collisions(int n_events){
    for(int i=0; i<n_events; i++)
    {
        float b = fImpact->GetRandom();

        Target->DistributeNucleons(-b/2);
        Projectile->DistributeNucleons(+b/2);

        int Npart = 0;
        int Ncoll = 0;

        for(int ip=0; ip<Projectile->GetMassNumber(); ip++){
            for(int it=0; it<Target->GetMassNumber(); it++){\
                float dx = Projectile->nucleon[ip].x - Target -> nucleon[it].x;
                float dy = Projectile->nucleon[ip].y - Target->nucleon[it].y;
                float dxy2 = dx*dx + dy*dy;

                if(dxy2 < sigma_nn_inel_fm2/pi){
                    Ncoll++;
                    if(Projectile->nucleon[ip].ncoll++ == 0) Npart++;
                    if(Target->nucleon[it].ncoll++ = 0) Npart++;
                }
            }
        }
        cout << "Event" << i << ": Npart = " << Npart;
            << ", Ncoll = " << Ncoll << endl;

    }
}


//Here we are defining a function that had not yet been defined 
void nucleus::DistributeNucleon(const float& x_offset, int A)
{
    //Offset describes the b parameter
    for(int i=0; i<A; i++){
        float r = ws -> GetRandom();
        float theta = th -> GetRandom();
        float phi = 2.*pi*gRandom -> Rndm();

        nucl[i].x = r*sin(theta) * cos(phi) + x_offset;
        nucl[i].y = r*sin(theta) * sin(theta) * sin(phi);
        nucl[i].z = r*cos(theta);

        nucl[i].ncoll = 0;
    }

}

void nucleus::DefineShape() 
{
    ws = new TF1("Woods-Saxon", "x*x/(1-exp((x-[0]/[1])))",0.,20.);
    ws->SetParameter(0, ws_radius);
    ws->SetParameter(1, ws_diffuseness);
}