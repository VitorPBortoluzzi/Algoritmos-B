void split(string vetor[], string str, string deli = " ")
{        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

string paraMaiusculo(string frase) 
{
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]); //transforma para maiusculo
    }
    return frase;
}