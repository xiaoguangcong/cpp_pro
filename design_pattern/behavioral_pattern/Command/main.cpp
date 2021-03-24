#include "Command.h"

int main()
{
    // 实例化调用者：按钮
    Button *button = new Button();

    // 按钮控制电灯
    Command* lampCmd = new LampCommand();
    button->setCommand(lampCmd);
    button->touch();
    button->touch();
    button->touch();

    printf("\n\n");

    // 按钮控制风扇
    Command *fanCmd = new FanCommand();
    button->setCommand(fanCmd);
    button->touch();
    button->touch();
    button->touch();

    return 0;
}