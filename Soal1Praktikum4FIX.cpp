#include <iostream>
#include <cstdlib> // for generating random numbers
#include <ctime> // for getting current time
#include <vector>
#include <algorithm>

using namespace std;

class Council {
private: 
    int coin;

public:
    Council() : coin(rand() % 900 + 100) {} // Randomly assign coin between 100 and 999

    bool SurrenderOrNot(int requiredCoin) const {
        return coin < requiredCoin;
    }

    int getCoin() const {
        return coin;
    }
};

class Troops {
protected:
    int health;
    int attack;

public:
    Troops(int health, int attack) : health(health), attack(attack) {}

    virtual ~Troops() {}

    virtual void giveAttack() const = 0;

    virtual void defend() const = 0;

    int getHealth() const {
        return health;
    }

    int getAttack() const {
        return attack;
    }
};

class Archer : public Troops {
public:
    Archer() : Troops(5, 20) {}

    void giveAttack() const override {
        cout << "Archer attacks the target!" << endl;
    }

    void defend() const override {
        cout << "Archer defends against the enemy!" << endl;
    }
};

class Knight : public Troops {
public:
    Knight() : Troops(10, 5) {}

    void giveAttack() const override {
        cout << "Knight attacks the target!" << endl;
    }

    void defend() const override {
        cout << "Knight defends against the enemy!" << endl;
    }
};

class Berserker : public Troops {
public:
    Berserker() : Troops(20, 5) {}

    void giveAttack() const override {
        cout << "Berserker attacks the target!" << endl;
    }

    void defend() const override {
        cout << "Berserker defends against the enemy!" << endl;
    }
};

class Golem : public Troops {
public:
    Golem() : Troops(100, 1) {}

    void giveAttack() const override {
        cout << "Golem attacks the target!" << endl;
    }

    void defend() const override {
        cout << "Golem defends against the enemy!" << endl;
    }
};

class Mage : public Troops {
public:
    Mage() : Troops(1, 100) {}

    void giveAttack() const override {
        cout << "Mage attacks the target!" << endl;
    }

    void defend() const override {
        cout << "Mage defends against the enemy!" << endl;
    }
};

class Demon {
private:
    int health;
    int attack;

public:
    Demon(int health, int attack) : health(health), attack(attack) {
    }

    int getHealth() const{
        return health;
    }

    int getAttack() const {
        return attack;
    }
};

struct TroopStrategy {
    int numArchers;
    int numKnights;
    int numBerserkers;
    int numGolems;
    int numMages;
};

void printStrategy(const TroopStrategy& Strategy) {
    cout << Strategy.numArchers << "A " << Strategy.numBerserkers << "B "
              << Strategy.numGolems << "G " << Strategy.numKnights << "K "
              << Strategy.numMages << "M" << endl;
}

bool isValidStrategy(const TroopStrategy& Strategy, const Council& council) {
    int totalCost = Strategy.numArchers * 20 + Strategy.numKnights * 5 +
                    Strategy.numBerserkers * 5 + Strategy.numGolems * 1 +
                    Strategy.numMages * 100;

    return totalCost <= council.getCoin();
}

void findBestStrategy(const Demon& demon, const Council& council) {
    int numKnightsNeeded = (demon.getHealth() + 4) / 5; // Round up the division

    TroopStrategy bestStrategy;
    int bestScore = -1;

    for (int numArchers = 0; numArchers <= 100; numArchers++) {
        for (int numBerserkers = 0; numBerserkers <= 20; numBerserkers++) {
            for (int numGolems = 0; numGolems <= 100; numGolems++) {
                for (int numMages = 0; numMages <= 10; numMages++) {
                    int remainingcoin = council.getCoin() - (numArchers * 20 + numKnightsNeeded * 2 + numBerserkers * 5 + numGolems * 1 + numMages * 100);

                    if (remainingcoin >= 0) {
                        TroopStrategy Strategy = {numArchers, numKnightsNeeded, numBerserkers,
                                                        numGolems, numMages};

                        int score = numArchers * 20 + numKnightsNeeded * 5 +
                                    numBerserkers * 5 + numGolems * 1 +
                                    numMages * 100;

                        if (score > bestScore) {
                            if (isValidStrategy(Strategy, council)) {
                                bestScore = score;
                                bestStrategy = Strategy;
                            }
                        }
                    }
                }
            }
        }
    }

    if (bestScore == -1) {
        cout << "Surrender: Kingdom cannot afford the required troops." << endl;
    } else {
        printStrategy(bestStrategy);
        cout << "coin left: " << council.getCoin() - (bestStrategy.numArchers * 20 + bestStrategy.numKnights * 5 + bestStrategy.numBerserkers * 5 +bestStrategy.numGolems * 1 +bestStrategy.numMages * 100) << endl;
    }
}

void runProgrammingLogic() {
    srand(time(NULL)); // Initialize random seed based on current time

    Council council;
    Demon demon(rand() % 980 + 20, rand() % 95 + 5); // Randomly assign health between 20 and 999, and attack between 5 and 99

    int requiredCoin = (demon.getHealth() + 4) / 5; // Round up the division

    if (council.SurrenderOrNot(requiredCoin)) {
        cout << "0A 0B 0G 0K 0M" << endl;
        cout << "Surrender: Kingdom cannot defeat the Demon with the available coin." << endl;
    } else {
        findBestStrategy(demon, council);
    }
}

int main() {
    runProgrammingLogic();

    return 0;
}