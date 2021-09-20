#include <iostream>
#include <Item.hpp>

int main()
{
    {
        std::shared_ptr<Item> parent = std::make_shared<Item>("p1");

        parent->addChild(std::make_shared<Item>("ch1", parent));
        parent->getChildByName("ch1")->addChild(std::make_shared<Item>("sch1_1", parent->getChildByName("ch1")));
        parent->getChildByName("ch1")->addChild(std::make_shared<Item>("sch1_2", parent->getChildByName("ch1")));
        parent->getChildByName("ch1")->addChild(std::make_shared<Item>("sch1_3", parent->getChildByName("ch1")));

        parent->addChild(std::make_shared<Item>("ch2", parent));
        parent->getChildByName("ch2")->addChild(std::make_shared<Item>("sch2_1", parent->getChildByName("ch2")));
        parent->getChildByName("ch2")->addChild(std::make_shared<Item>("sch2_2", parent->getChildByName("ch2")));
        parent->getChildByName("ch2")->getChildByName("sch2_2")->addChild(
            std::make_shared<Item>("subsch2_2_1", parent->getChildByName("ch2")->getChildByName("sch2_2")));
        parent->getChildByName("ch2")->getChildByName("sch2_2")->addChild(
            std::make_shared<Item>("subsch2_2_2", parent->getChildByName("ch2")->getChildByName("sch2_2")));
        parent->getChildByName("ch2")->getChildByName("sch2_2")->addChild(
            std::make_shared<Item>("subsch2_2_3", parent->getChildByName("ch2")->getChildByName("sch2_2")));
        parent->getChildByName("ch2")->getChildByName("sch2_2")->addChild(
            std::make_shared<Item>("subsch2_2_4", parent->getChildByName("ch2")->getChildByName("sch2_2")));

        parent->addChild(std::make_shared<Item>("ch3"));

        parent->log("-");

        parent.reset();
    }

    return 0;
}
