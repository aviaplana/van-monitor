#ifndef BUTTON_INTERRUPT_H
#define BUTTON_INTERRUPT_H

class ButtonInterrupt {
    public:
        ButtonInterrupt(int);
        void begin();
        void interruptionRoutine();
        bool hasInterruption();
        void clearInterruption();
        int getPin();
        unsigned long getLastInterruption() { return last_interruption; }

    private:
        int pin;
        bool interruption_flag = false;
        unsigned long last_interruption = 0;
        unsigned long interruption_interval = 300;
};

#endif