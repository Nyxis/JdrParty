#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Logger
{
private:
    static Logger *instance;

public:
    static Logger *getInstance()
    {
        if (!instance)
        {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string &message)
    {
        std::cout << message << std::endl;
    }
};

Logger *Logger::instance = nullptr;

class TirageAleatoire
{
public:
    virtual std::string genererResultat() = 0;
    virtual std::string getNomMateriel() = 0;
};

class Piece : public TirageAleatoire
{
private:
    int nombreLances;

public:
    Piece(int nombreLances)
    {
        this->nombreLances = nombreLances;
    }

    std::string genererResultat() override
    {
        return lancerPiece(nombreLances) ? "pile" : "face";
    }

    std::string getNomMateriel() override
    {
        return "Piece";
    }

private:
    bool lancerPiece(int nombreLances)
    {
        if (nombreLances == 1)
        {
            return rand() % 2 == 0;
        }
        else
        {
            return lancerPiece(nombreLances - 1) && (rand() % 2 == 0);
        }
    }
};

class De : public TirageAleatoire
{
private:
    std::vector<int> faces;
    int nombreLances;

public:
    De(std::vector<int> faces, int nombreLances)
    {
        this->faces = faces;
        this->nombreLances = nombreLances;
    }

    De(int nombreFaces, int nombreLances)
    {
        for (int i = 1; i <= nombreFaces; i++)
        {
            this->faces.push_back(i);
        }
        this->nombreLances = nombreLances;
    }

    std::string genererResultat() override
    {
        int resultat = 0;
        for (int i = 0; i < nombreLances; i++)
        {
            int index = rand() % faces.size();
            resultat += faces[index];
        }
        return std::to_string(resultat);
    }

    std::string getNomMateriel() override
    {
        return "De";
    }

    int getNombreLances()
    {
        return nombreLances;
    }
};

class DeckDeCartes : public TirageAleatoire
{
private:
    int nombreCouleurs;
    int nombreValeurs;

public:
    DeckDeCartes(int nombreCouleurs, int nombreValeurs)
    {
        this->nombreCouleurs = nombreCouleurs;
        this->nombreValeurs = nombreValeurs;
    }

    std::string genererResultat() override
    {
        int couleur = rand() % nombreCouleurs + 1;
        int valeur = rand() % nombreValeurs + 1;
        return std::to_string(couleur) + " " + std::to_string(valeur);
    }

    std::string getNomMateriel() override
    {
        return "Deck de cartes";
    }
};

class GameMaster
{
private:
    std::vector<TirageAleatoire *> materiel;

public:
    GameMaster()
    {
        materiel.push_back(new De(6, 1));
        materiel.push_back(new DeckDeCartes(3, 18));
        materiel.push_back(new DeckDeCartes(4, 13));
        materiel.push_back(new Piece(1));
        materiel.push_back(new Piece(1));
    }

    ~GameMaster()
    {
        for (TirageAleatoire *obj : materiel)
        {
            delete obj;
        }
    }

    std::pair<std::string, std::string> pleaseGiveMeACrit(int tauxReussite, int tauxCritique, int tauxFumble)
    {
        int index = rand() % materiel.size();
        TirageAleatoire *materielChoisi = materiel[index];
        std::string resultat = materielChoisi->genererResultat();
        std::string nomMateriel = materielChoisi->getNomMateriel();

        int pourcentageTotal = tauxReussite + tauxCritique + tauxFumble;

        int hasard = rand() % 100 + 1;

        std::string resultType;
        if (hasard <= tauxFumble * 100 / pourcentageTotal)
        {
            resultType = "Fumble";
        }
        else if (hasard <= (tauxFumble + tauxReussite) * 100 / pourcentageTotal)
        {
            resultType = "Succes";
        }
        else if (hasard <= (tauxFumble + tauxReussite + tauxCritique) * 100 / pourcentageTotal)
        {
            resultType = "Critique";
        }
        else
        {
            resultType = "Echec";
        }

        std::string detail;
        if (nomMateriel == "De")
        {
            detail = resultat;
        }
        else if (nomMateriel == "Piece")
        {
            detail = resultat == "pile" ? "Pile" : "Face";
        }
        else
        {
            std::vector<std::string> couleurs = {"Pique", "Coeur", "Carreau", "Trefle"};
            std::vector<std::string> valeurs = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};

            int couleurIndex = std::stoi(resultat.substr(0, resultat.find(" "))) - 1;
            int valeurIndex = std::stoi(resultat.substr(resultat.find(" ") + 1)) - 1;

            detail = valeurs[valeurIndex] + " de " + couleurs[couleurIndex];
        }
        Logger::getInstance()->log("Resultat du tirage : " + resultType);
        Logger::getInstance()->log("Detail du resultat : " + detail + " (" + nomMateriel + ")");

        return std::make_pair(resultType, detail + " (" + nomMateriel + ")");
    }
};

int main()
{
    srand(time(0));
    GameMaster gameMaster;
    auto result = gameMaster.pleaseGiveMeACrit(60, 10, 5);
    return 0;
}
