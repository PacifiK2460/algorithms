template <typename Type>
struct node{
    // Nodo: con un valor numérico y un puntero al sig. nodo. 
    Type value = 0;
    node *next = nullptr;
};
template <typename Type>
struct linked_list{
    double tam = 0;
    struct node<Type> *primero = nullptr;
    struct node<Type> *ultimo  = nullptr;
    struct node<Type> *temp  = nullptr;

    void append(Type value){
        struct node<Type> *new_node = new node<Type>;
        new_node -> value = value;
        new_node -> next  = nullptr;

        if( primero == nullptr )
            primero = new_node;
        else
        {
            temp = primero;
            while(temp->next != nullptr)
                temp = temp -> next;
            // Una vez en el ultimo nodo (en blanco), 
            // este es reasignado con un nodo (dirección) funcional.
            temp -> next = new_node;
            ultimo = new_node;
        }
        tam++;
    }

    void insert_at(double index, Type value){
        if(index > tam)
            throw "Ilegal Memory Acces";
        temp = primero;
        for(int i = 0; i < index; i++)
            temp = temp -> next;
        struct node<Type> *new_node = new node<Type>;
        new_node -> value = value;
        new_node -> next  = temp -> next;
        temp -> next = new_node;
        tam++;        
    }

    void edit(double index, Type value){
        if(index > tam)
            throw "Ilegal Memory Acces";
        temp = primero;
        for(int i = 0; i < index; i++)
            temp = temp -> next;
        temp -> value = value;
    }

    void pop(double index){
        if(index > tam)
            throw "Ilegal Memory Acces";
        if(index == 0){
            temp = primero -> next;
            delete primero;
            primero = temp;
        } else {
            struct node<Type> *temporal = primero;
            temp = primero -> next;
            for(int i=1;i<index;i++){
                temporal = temp;
                temp = temp -> next;
            }
            if(index == tam-1){
                ultimo = temporal;
                delete temporal -> next;
            }
            else{
                temporal -> next = temp -> next;
                delete temp;
            }
        }
        tam--;
    }

    Type item(double index){
        if(index > tam)
            throw "Ilegal Memory Acces";
        temp = primero;
        for(int i = 0; i < index; i++)
            temp = temp -> next;
        return temp -> value;
    }
    Type last(void){
        return ultimo -> value;
    }
    Type first(void){
        return primero -> value;
    }
    double size(void){
        return tam;
    }
};