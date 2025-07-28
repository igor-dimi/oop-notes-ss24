 #include <iostream>
 #include <numeric>
 #include <cmath>
 #include <memory>
 #include <vector>
 #include <algorithm>

 struct AbstractCoinToss
 {
    virtual int Value() = 0;
 };

 struct Heads : public AbstractCoinToss
 {
    int Value() override {return 0;}
 };

struct Tails : public AbstractCoinToss
{
    int Value() override {return 1;}
};

struct RandomFactory
{
    std::unique_ptr<AbstractCoinToss> operator()()
    {
        switch (rand() % 2) {
            case 0: return std::make_unique<Heads>();
            case 1: return std::make_unique<Tails>(); 
        }
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<AbstractCoinToss>> samples(1000);
    std::generate(samples.begin(), samples.end(), RandomFactory());
    int sum = 0;
    for (const auto& r : samples) sum += r->Value();
    std::cout << "res: " << sum << std::endl;
    std::unique_ptr<AbstractCoinToss> sample_arr[10];
    for (int i = 0; i < 10; i++) sample_arr[i] = RandomFactory()();




    auto ptr = RandomFactory()();
    auto ptr2 = RandomFactory()();
    std::cout << "ptr val: " << ptr->Value() << std::endl;
    std::cout << "ptr2 val: " << ptr2->Value() << std::endl;

    int sum2 = 0;
    for (int i = 0; i < 10; i++) sum2+= sample_arr[i]->Value();

    std::cout << "res2: " << sum2 << std::endl;
    return 0;
}
