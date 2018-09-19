#include "headers.h"
#include "methods.h"


void setValues(struct elements *e) {

    int i;
    for(i=0;i<8;i++)
        (e->flags)[i] = 0;
    for(i=0;i<7;i++)
        (e->registers)[i] = "00";
}
    
    
void getStart(struct elements *e) {

    string str;
    while(1) {

        cout << "Enter the starting address : ";
        cin >> str;
        if(validAddress(str)) {

            e->pc = str;
            e->start = str;
            break;
        }
        else
            cout << "Invalid Address! Try again " << endl;
    }
}


void input(struct elements *e) {

    string line;
    cout << "\nEnter the 8085 code here : " << endl;
    cin.ignore();
    fflush(stdin);
    while(1) {

        cout << e->pc << " : ";
		getline(cin, line);
		transform(line.begin(), line.end(), line.begin(), ::toupper);
        // if(line == "\0")
            // break;
        if(validInst(line)) {

            e->memory[e->pc] = line;
            updatePc(e);
            if(line.compare("HLT")==0 )break;
        }
        else
            cout << "\nInvalid instruction! Enter correct instruciton!" << endl;
    }
    cout << "\nEnd of input!" << endl;
    execute(e);	
}
    
void inputFromFile(struct elements *e) {

    string line;
    while(1) {

        //cout << e->pc << " : ";
        //cin.ignore();
        //fflush(stdin);
		getline(cin, line);
		transform(line.begin(), line.end(), line.begin(), ::toupper);
        if(line == "\0")
            break;
        else if(validInst(line)) {

            e->memory[e->pc] = line;
            updatePc(e);
            if(line.compare("HLT")==0 )break;
        }
        else
        {
            cout << "\nInvalid instruction! Enter correct instruciton!\n"<<line << endl;
          	return;
		}
    }
    //cout << "\nEnd of input!" << endl;
    execute(e);
}
    


int main(int argc, char* argv[]) {

    struct elements e;
    setValues(&e);
    string tmp;		
    switch(argc) {

        case 1:
            cout << "\nNo input file selected!\nEnter code from command line!" << endl;
            getStart(&e);
            input(&e);
            display(&e);
        break;
        case 2:
            tmp = argv[1];
            if(tmp.compare("--debug")==0 )
            {
        	   cout << "Debugging mode selected" << endl;
        	   getStart(&e);
  			   input(&e);
               display(&e);
               debug(&e);
            }
            else
            {
                cout << "\nSource file provided" << endl;
                getStart(&e);
  		        //e.start = e.pc = "2000";
                freopen(argv[1],"r",stdin);// ./simulator input.asm
                inputFromFile(&e);
                display(&e);
            }
        break;
        case 3:
            cout << "Debugging mode with source file selected" << endl;
            getStart(&e);
  		    freopen(argv[2],"r",stdin);// ./simulator --debug input.asm
            inputFromFile(&e);
            //DEBUG
            display(&e);
            debug(&e);
        break;
        default :
            cout << "Invalid mode selected" << endl;
    }
    return 0;
}
