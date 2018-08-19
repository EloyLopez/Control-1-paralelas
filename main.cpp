#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
     /**
     * 
     * @param argc Codigo Estacion de Origen
     * @param argv Codigo Estacion de Destino
     * @return 
     */

    string inicio;
    string fin;
    //Si es 1 se retrocede, si es 0 se avanza
    int origen=0,destino=0;
    //guarda
    int guarda_x, guarda_y,guarda_xf,guarda_yf,valor_i,valor_f;
    //distancia
    int distancia;
    //contadores
    int x=0,y=0,z=0,i=0,j=0,h=1,k,l=0,n=0,m=0,menor_f=999,menor_i=999,u=0,t=0,w=0;
    //guarda las combinaciones mas cercanas
    int comb_i[3][1],comb_f[3][1];
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
    //FUNCION QUE MUESTRA COMO LA ESTACION DE ORIGEN GUARDANDO SU FILA Y SU COLUMNA
    for(y=0;y<12;y++)
    {
        for(x=0;x<30;x++)
        {
            if(inicio==lineas[y][x])
            {
                cout<<endl<<"inicio"<<endl;
                cout<<lineas[y+1][x]<<endl;
                find_li=y;
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
                find_ef=x;
            }
        }        
}
    /*
     * AQUI EMPIEZA EL ORIGEN
     */
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
                      comb[h][u]=k;
                      
                      t++;
                              if(t==2)
                              {
                                  t=0;
                                  u++;
                              }
                      h++;
                  }
                }
                j++;  
            }
        }
    }
    //DISTANCIAS DESDE EL ORIGEN HASTA LA COMBINACION MAS CERCANA
    for(l=0;l<i;l++)
    {
        if(comb[0][l]-find_ei<0)
        {
             resta[l]=(comb[0][l]-find_ei)*-1; 
             
             origen=1;
        }
        
        else
        {
          resta[l]=comb[0][l]-find_ei;
          origen=0;
        }
            
        //COMBINACION MAS PROXIMA DESDE EL INICIO
        if(resta[l]<menor_i)
        {
            
            if(resta[l]!=0)
            {
                //GUARDA LA COMBINACION MAS CERCA AL ORIGEN Y MUESTRA CON QUE LINEAS COMBINA
                menor_i=resta[l];
                comb_i[0][0]=comb[0][l];
                comb_i[1][0]=comb[1][l];
                comb_i[2][0]=comb[2][l];
            } 
        }   
    }
   
    /*
     AQUI EMPIEZA EL DESTINO
     */
    //-CUENTA LA CANTIDAD DE COMBINACION QUE TIENE LA LINEA DE DESTINO
    for(x=0;x<30;x++)                            
    {
        for(z=0;z<11;z++)
        {
            if(LC[0][z]==lineas[find_lf+1][x])          
            {
                n++;
            }
        }
    }
    
     int comb_d[3][n],resta_d[n];
      //COMB_D GUARDA EL NUMERO DE LA ESTACION EN LA LINEA INICIAL Y CON LAS LINEAS QUE COMBINA
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
     u=0;
     t=0;
    for(x=0;x<30;x++)
    {
        for(z=0;z<11;z++)
        {
            
            if(LC[0][z]==lineas[find_lf+1][x])
            {
                comb_d[0][m]=x;
                h=1;
               for(k=0;k<7;k++)
                {
                  if(LC[k][z]=="1")
                  {
                      comb_d[h][u]=k;
                      t++;
                              if(t==2)
                              {
                                  t=0;
                                  u++;
                              }
                      h++;
                  }
                }
                m++;  
            }
        }
    }
     //DISTANCIAS DESDE EL DESTINO A LA COMBINACION MAS CERCANA
    for(l=0;l<n;l++)
    {
        if(comb_d[0][l]-find_ef<0)
        {
             resta_d[l]=(comb_d[0][l]-find_ef)*-1; 
             destino=1;
        }
        
        else
        {
            resta_d[l]=comb_d[0][l]-find_ef;
            destino=0;
        }
            
        
        //COMBINACION MAS PROXIMA DESDE EL DESTINO
        if(resta_d[l]<menor_f)
        {
            
            if(resta_d[l]!=0)
            {
                //OBTIENE EL LA MENOR DISTANCIA ENTRE DESTINO Y SU COMBINACION
                menor_f=resta_d[l];
                //GUARDA NOMBRE DE LA COMBINACION Y CON QUE LINEAS COMBINA
                comb_f[0][0]=comb_d[0][l];
                comb_f[1][0]=comb_d[1][l];
                comb_f[2][0]=comb_d[2][l];
            }
            
        }
        
    }
     string avance_inicio[menor_i];
     string avance_final[menor_f];
     //DISTANCIA DE UNA COMBINACION Y MISMA ESTACION DE COMBINACION
     if((comb_f[1][0]==comb_i[1][0]||comb_f[2][0]==comb_i[1][0]||comb_f[2][0]==comb_i[2][0]||comb_f[1][0]==comb_i[2][0])&& lineas[find_lf+1][comb_f[0][0]]==lineas[find_li+1][comb_i[0][0]])
     {
        //MUESTA LA DISTANCIA MAS CORTA
         if(origen==0)
         {
             y=1;
             for(x=0;x<menor_i;x++)
             {
                 avance_inicio[x]=lineas[find_li+1][find_ei+y];
                 y++;
             }
         }
         else
         {
             y=1;
             for(x=0;x<menor_i;x++)
             {
                 avance_inicio[x]=lineas[find_li+1][find_ei-y];
                 y++;
             }
         }
        if(destino==0)
         {
             y=1;
             for(x=0;x<(menor_f-1);x++)
             {
                 avance_final[x]=lineas[find_lf+1][find_ef+y];
                 
                 y++;
             }
         }
         else
         {
             y=1;
             for(x=0;x<(menor_f-1);x++)
             {
                 
                 avance_final[x]=lineas[find_lf+1][find_ef-y];
                 y++;
             }
         }
         cout<<endl<<lineas[find_li+1][find_ei]<< "-";
         for(x=0;x<menor_i;x++)
             {
                cout<< avance_inicio[x]<<"-";
                
             }
         for(x=0;x<menor_f;x++)
             {
                cout<< avance_final[x]<<"-";
                
             }
         cout<<lineas[find_lf+1][find_ef]<<endl;
         cout<<endl<<menor_f+menor_i<<endl;   
     }
     //DISTANCIA DE UNA COMBINACION Y DIFERENTE ESTACION DE COMBINACION
     else if((comb_f[1][0]==comb_i[1][0]||comb_f[2][0]==comb_i[1][0]||comb_f[2][0]==comb_i[2][0]||comb_f[1][0]==comb_i[2][0])&& lineas[find_lf+1][comb_f[0][0]]!=lineas[find_li+1][comb_i[0][0]])
     {
         //distancia desde el destino a su combinacion mas cercana
         for(x=0;x<30;x++)
         {
             if(lineas[find_li+1][comb_i[0][0]]==lineas[find_lf+1][x])
             {
                 for(y=0;y<30;y++)
                  {
                        if(lineas[find_lf+1][comb_f[0][0]]==lineas[find_lf+1][y])
                        {
                             distancia=y;
                        }
                   }
                 
                 if((distancia-x)<0)
                 {
                     distancia=(distancia-x)*-1;
                 }
                 else
                     distancia=distancia-x;    
             }
             
             else
             {
                 
             }  
         }
         cout<<endl<<menor_f+menor_i+distancia<<endl; 
     }
     
     //COMBINACION 3 LINEAS
     
     else if((comb_f[1][0]!=comb_i[1][0]||comb_f[2][0]!=comb_i[1][0]||comb_f[2][0]!=comb_i[2][0]||comb_f[1][0]!=comb_i[2][0]))
     {
         for(y=0;y<12;y++)
         {
             for(x=0;x<30;x++)
                {
                 //GUARDA LA LINEA EN LA QUE ESTA LA ESTACION DONDE SE COMBINA
                    if(lineas[find_lf+1][comb_f[0][0]]==lineas[y][x] && (find_lf+1)!=y)
                      {
                        guarda_yf=y;
                            if(y==1)
                            {
                                guarda_y=1;
                            }
                            if(y==3)
                            {
                                guarda_y=2;
                            }
                            if(y==5)
                            {
                                guarda_y=3;
                             }
                             if(y==7)
                             {
                                guarda_y=4;
                            }
                             if(y==9)
                             {
                                guarda_y=5;
                             }
                             if(y==11)
                            {
                                guarda_y=6;
                             }
                      }
                }
             for(x=0;x<30;x++)
             {
                 if(lineas[find_li+1][comb_i[0][0]]==lineas[y][x]&& (find_li+1)!=y)
                 {
                     //GUARDA LA LINEA EN LA QUE ESTA LA ESTACION DONDE SE COMBINA
                     guarda_xf=y;
                     if(y==1)
                            {
                                guarda_x=1;
                            }
                            if(y==3)
                            {
                                guarda_x=2;
                            }
                            if(y==5)
                            {
                                guarda_x=3;
                             }
                             if(y==7)
                             {
                                guarda_x=4;
                            }
                             if(y==9)
                             {
                                guarda_x=5;
                             }
                             if(y==11)
                            {
                                guarda_x=6;
                             }
                 }
                      
             }
             
         }
         for(y=0;y<11;y++)
         {
             //OBTENGO NOMBRE DE LA ESTACION DONDE SE COMBINA
             if(LC[guarda_y][y]=="1"&& LC[guarda_x][y]=="1")
             {
                 for(x=0;x<30;x++)
                 {
                     if(lineas[guarda_yf][x]==LC[0][y])
                    {
                         for(z=0;z<30;z++)
                         {
                             //CALCULO LA DISTANCIA DESDE LA COMBIONACION FINAL HASTA LA PRIMERA COMBINACION DESDE LA ESTACION DESTINO
                             if(lineas[guarda_yf][z]==lineas[find_lf+1][comb_f[0][0]])
                             {
                                 
                               if((x-z)<0)
                                 {
                                     valor_f=(x-z)*-1;
                                 }
                                 else
                                     valor_f=x-z; 
                             }
                         } 
                    }
                 }
                 for(x=0;x<30;x++)
                 {
                     if(lineas[guarda_xf][x]==LC[0][y])
                    {
                         for(z=0;z<30;z++)
                         {
                             //CALCULO LA DISTANCIA DESDE LA COMBIONACION FINAL HASTA LA PRIMERA COMBINACION DESDE LA ESTACION ORIGEN
                             if(lineas[guarda_xf][z]==lineas[find_li+1][comb_i[0][0]])
                             {
                                 
                               if((x-z)<0)
                                 {
                                     valor_i=(x-z)*-1;
                                 }
                                 else
                                     valor_i=x-z;     
                             }
                         }
                         
                    }
                 } 
             }
         }
       cout<<endl<<valor_i+valor_f+menor_f+menor_i<<endl;  
     } 
}
