
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    string inicio;
    string fin;
    //contadores
    int x=0,y=0,z=0,i=0,j=0,h=1,k,l=0;
    //variable para estacion inicial y linea inicial
    int find_ei,find_li,find_lii;
    //variable para estacion final y linea final
    int find_ef,find_lf,find_lff;
    
    //find_ei y find_ef muestran la posicion en que se encuentra esa estacion en su linea
    
    /*find_li y find_lf muestran las lineas
     * find_li=0 linea 1
     * find_li=2 linea 2
     * find_li=4 linea 4
     * find_li=6 linea 4A
     * find_li=8 linea 5
     * find_li=10 linea 6
    */
    //estaciones del metro
    string lineas[12][30]={
    "SP","NP","PJ","LR","EC","AH","US","EL","LA","RP","LH","LM","CH","SL","UC","BA","SA","MM","PV","LE","TB","GO","AL","EM","MQ","HM","LD","0","0","0",
    "SAN PABLO","NEPTUNO","PAJARITOS","LAS REJAS","ECUADOR","SAN ALBERTO HURTADO","UNIVERSIDAD DE SANTIAGO","ESTACION CENTRAL","ULA","REPUBLICA","LOS HEROES","LA MONEDA","UNIVERSIDAD DE CHILE","SANTA LUCIA","UNIVERSIDAD CATOLICA","BAQUEDANO","SALVADOR","MANUEL MONTT","PEDRO DE VALDIVIA","LOS LEONES","TOBALABA","EL GOLF","ALCANTARA","ESCUELA MILITAR","MANQUEHUE","HERNANDO DE MAGALLANES","LOS DOMINICOS","0","0","0",
    "LC","EP","LO","CN","DE","LV","SM","LL","FR","RO","PQ","TO","HE","AN","CA","PT","CB","CE","EI","DO","ZA","AV","0","0","0","0","0","0","0","0",
    "LA CISTERNA","EL PARRON","LO OVALLE","CIUDAD DEL NIÑO","DEPARTAMENTAL","LO VIAL","SAN MIGUEL","EL LLANO","FRANKLIN","RONDIZZONI","PARQUE OHIGGINS","TOESCA","LOS HEROES","SANTA ANA","PUENTE CAL Y CANTO","PATRONATO","CERRO BLANCO","CEMENTERIOS","EINSTEIN","DORSAL","ZAPADORES","VESPUCIO NORTE","0","0","0","0","0","0","0","0",
    "TOB","COL","BIL","PDG","SBO","PEG","LOR","RGR","LPR","RQU","LTO","MAC","VMA","VVA","RMA","TRI","SJE","LQU","ECO","HSR","LME","PIN","PPA","0","0","0","0","0","0","0",
    "TOBALABA","CRISTOBAL COLON","FRANCISCO BILBAO","PRINCIPE DE GALES","SIMON BOLIVAR","PLAZA EGAÑA","LOS ORIENTALES","GRECIA","LOS PRESIDENTES","QUILIN","LAS TORRES","MACUL","VICUÑA MACKENNA","VICENTE VALDES","ROJAS MAGALLANES","TRINIDAD","SAN JOSE DE LA ESTRELLA","LOS QUILLAYES","ELISA CORREA","HOSPITAL SOTERO DEL RIO","LAS MERCEDES","PROTECTORA DE LA INFANCIA","PLAZA DE PUENTE ALTO","0","0","0","0","0","0","0",
    "VIM","SJU","LGR","SRO","SRA","LCI","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
    "VICUÑA MACKENNA","SANTA JULIA","LA GRANJA","SANTA ROSA","SAN RAMON","LA CISTERNA","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
    "PM","SB","DS","MT","LP","LS","BR","PU","SO","PR","BL","GL","QN","RC","NA","PZ","BE","BQ","PB","SI","IR","NU","RA","CV","AG","SJ","PE","MA","LF","VV",
    "PLAZA MAIPU","SANTIAGO BUERAS","DEL SOL","MONTE TABOR","LAS PARCELAS","LAGUNA SUR","BARRANCAS","PUDAHUEL","SAN PABLO","LO PRADO","BLANQUEADO","GRUTA DE LOURDES","QUINTA NORMAL","CUMMING","SANTA ANA","PLAZA DE ARMAS","BELLAS ARTES","BAQUEDANO","PARQUE BUSTAMANTE","SANTA ISABEL","IRARRAZAVAL","ÑUBLE","RODRIGO DE ARAYA","CARLOS VALDOVINOS","CAMINO AGRICOLA","SAN JOAQUIN","PEDRERO","MIRADOR","BELLAVISTA DE LA FLORIDA","VICENTE VALDES",
    "CER","LVA","PAC","FRA","BIO","NUB","ESN","NUO","ISU","LEN","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
    "CERRILLOS","LO VALLEDOR","PEDRO AGUIRRE CERDA","FRANKLIN","BIO BIO","ÑUBLE","ESTADIO NACIONAL","ÑUÑOA","INES DE SUAREZ","LOS LEONES","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"
    };
    //estaciones de combinacion
    string LC[7][11] = {
        "SAN PABLO","SANTA ANA","LOS HEROES","FRANKLIN","BAQUEDANO","ÑUBLE","LOS LEONES","TOBALABA","VICUÑA MACKENNA","VICENTE VALDES","LA CISTERNA",
        "1","0","1","0","1","0","1","1","0","0","0",
        "0","1","1","1","0","0","0","0","0","0","1",
        "0","0","0","0","0","0","0","1","1","1","0",
        "0","0","0","0","0","0","0","0","1","0","1",
        "1","1","0","0","1","1","0","0","0","1","0",
        "0","0","0","1","0","1","1","0","0","0","0"};
    cout<<endl<<"Estacion de inicio"<<endl;
    cin>>inicio;
    cout<<endl<<"Estacion de termino"<<endl;
    cin>>fin;
    for(y=0;y<12;y++)
    {
        for(x=0;x<30;x++)
        {
            if(inicio==lineas[y][x])
            {
                cout<<endl<<"inicio"<<endl;
                cout<<lineas[y+1][x]<<endl;
                find_li=y;
                if(y==0)
                {
                    find_lii=1;
                }
                 if(y==2)
                {
                    find_lii=2;
                }
                 if(y==4)
                {
                    find_lii=3;
                }
                 if(y==6)
                {
                    find_lii=4;
                }
                 if(y==8)
                {
                    find_lii=5;
                }
                 if(y==10)
                {
                    find_lii=6;
                }
                find_ei=x;
            }
        }        
    }
    for(y=0;y<12;y++)
    {
        for(x=0;x<30;x++)
        {
            if(fin==lineas[y][x])
            {
                cout<<endl<<"fin"<<endl;
                cout<<lineas[y+1][x]<<endl;
                find_lf=y;
                if(y==0)
                {
                    find_lff=1;
                }
                 if(y==2)
                {
                    find_lff=2;
                }
                 if(y==4)
                {
                    find_lff=3;
                }
                 if(y==6)
                {
                    find_lff=4;
                }
                 if(y==8)
                {
                    find_lff=5;
                }
                 if(y==10)
                {
                    find_lff=6;
                }
                find_ef=x;
            }
        }        
    }
    
    //MUESTRA LA CANTIDAD COMBINACIONES DE LA LINEA DE INICIO
    for(x=0;x<30;x++)
    {
        for(z=0;z<11;z++)
        {
            if(LC[0][z]==lineas[find_li+1][x])          
            {
                i++;
            }
        }
    }
    int comb[3][i],resta[i];
    //COMB GUARDA EL NUMERO DE LA ESTACION EN LA LINEA INICIAL Y CON LAS LINEAS QUE COMBINA
    /*
     * Lineas
     * posicion 0= nombre estacion
     * posicion 1 y 2= indican linea con la que combina
     * 1=linea 1
     * 2=linea 2
     * 3=linea 4
     * 4=linea 4A
     * 5=linea 5
     * 6=linea 6
     * 
     * ejemplo
     * comb[0][0]=san pablo
     * comb[1][0]= 1 (combina en la linea 1)
     * comb[2][0]= 5 (combina en la linea 5)
     */
    for(x=0;x<30;x++)
    {
        for(z=0;z<11;z++)
        {
            
            if(LC[0][z]==lineas[find_li+1][x])
            {
                comb[0][j]=x;
              
                h=1;
               for(k=0;k<7;k++)
                {
                  if(LC[k][z]=="1")
                  {
                      comb[h][z]=k;
                      h++;
                  }
                }
                j++;  
            }
        }
    }
    for(l=0;l<i;l++)
    {
        resta[l]=comb[0][l]-find_ei;
        for(x=1;x<3;x++)
        {
            if(comb[x][0]==find_lii)
            {
                
            }
        }
    }
    for(x=0;x<30;x++)
    {
        for(z=0;z<11;z++)
        {
            if(LC[0][z]==lineas[find_lf+1][x])        //find_lf cantidad de combinaciones que tiene la linea destino  
            {
                i++;
            }
        }
    }
      //COMB GUARDA EL NUMERO DE LA ESTACION EN LA LINEA INICIAL Y CON LAS LINEAS QUE COMBINA
    /*
     * Lineas
     * posicion 0= nombre estacion
     * posicion 1 y 2= indican linea con la que combina
     * 1=linea 1
     * 2=linea 2
     * 3=linea 4
     * 4=linea 4A
     * 5=linea 5
     * 6=linea 6
     * 
     * ejemplo
     * comb[0][0]=san pablo
     * comb[1][0]= 1 (combina en la linea 1)
     * comb[2][0]= 5 (combina en la linea 5)
     */
    for(x=0;x<30;x++)
    {
        for(z=0;z<11;z++)
        {
            
            if(LC[0][z]==lineas[find_lf+1][x])
            {
                comb[0][j]=x;
              
                h=1;
               for(k=0;k<7;k++)
                {
                  if(LC[k][z]=="1")
                  {
                      comb[h][z]=k;
                      h++;
                  }
                }
                j++;  
            }
        }
    }
    for(l=0;l<i;l++)
    {
        resta[l]=comb[0][l]-find_ei;
        for(x=1;x<3;x++)
        {
            if(comb[x][0]==find_lii)
            {
                
            }
        }
    }
}



