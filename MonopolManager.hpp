#pragma once

#include <iostream>
#include <cmath>
#include "Board.hpp"
#include "Chance.hpp"
#include "Square.hpp" 
#include "Tax.hpp" 
#include "WaterCompany.hpp" 
#include "ElectricCompany.hpp" 
#include "EdgeSquare.hpp" 
#include <ctime> 
#include <cstdlib>  // For rand() and srand()
#include "Player.hpp"

#include <memory>
#include <SFML/Graphics.hpp>


class Player;  // Forward declaration


using namespace std;


// Declare global strings here using extern
extern std::string GLOBAL_START_ICON;
extern std::string GLOBAL_GOTOJAIL_ICON;
extern std::string GLOBAL_VISITING_ICON;
extern std::string GLOBAL_FREE_PRAKING_ICON;




class MonopolManager{

    private:
        //Board board; 
        std::map<std::string, sf::Texture> textures; // Store textures
        std::vector<std::shared_ptr<Player>> players;
        std::vector<Chance> gameChanceCards;
        std::vector<std::string> chanceStrings;
        std::shared_ptr<Player> currentPlayer; 
       
        MonopolManager();

    public:
         // Deleted copy constructor and assignment operator
        MonopolManager(const MonopolManager&) = delete;
        MonopolManager& operator=(const MonopolManager&) = delete;

        // Static method to get the instance of the singleton
        static MonopolManager& getInstance() {
            static MonopolManager instance; // Guaranteed to be destroyed, instantiated on first use
            return instance;
        }

        static float StartMoney;

        std::vector<std::shared_ptr<Player>>& getPlayers();
        std::shared_ptr<Player>& getCurrentPlayer();
        void setCurrentPlayer(std::shared_ptr<Player>& p);
        std::vector<Chance>& getGameChanceCards();
        int RollDice();
        std::shared_ptr<Player>* CheckStreetOwner(const std::shared_ptr<Square>& square);
        std::shared_ptr<Player>* CheckTrainOwner(const std::shared_ptr<Square>& square);
        std::shared_ptr<Player>* CheckWaterCompanyOwner(const std::shared_ptr<Square>& square);
        std::shared_ptr<Player>* CheckElectricCompanyOwner(const std::shared_ptr<Square>& square);
        void CheckTaxPrice(Tax* tax);
        void AddChance();
        void AddCommunityChest();
        float getActuallBillOfSquare(std::shared_ptr<Square>& square,std::shared_ptr<Player>* ownPlayer);
        void BuyStreet(Street* street);
        void BuyTrain(Train* train);
        void BuyWaterCompany(WaterCompany* waterCompany);
        void BuyElectricCompanyOwner(ElectricCompany* electricCompany);
        void UpgradeStreet(Street* street);
        void CheckEdgeSquare(EdgeSquare* edgeSquare);
        void CheckEdgeSquareType(std::shared_ptr<Square>& square);
        bool ChargePlayer(std::shared_ptr<Player>& src,std::shared_ptr<Player>& dst, float amount);
        void TransferAllProperties(std::shared_ptr<Player>& src,std::shared_ptr<Player>& dst);
        bool DeleteAllProperties();
        void GoToJail();
        void GrantPlayerMoney(float sum);
        bool areAllRestPlayersHaveBankRupt(std::shared_ptr<Player>& p);
        std::shared_ptr<Player>* CheckIsWinner();
        void SetIcon(std::shared_ptr<Square>& square, const std::string& iconName);

};