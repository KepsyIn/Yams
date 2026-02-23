#ifndef YAMS_CONTROLLER_H
#define YAMS_CONTROLLER_H

#include "../model/YamsModel.h"
#include "../view/YamsView.h"

class YamsController {
private:
    YamsModel& model;
    YamsView& view;

public:
    YamsController(YamsModel& m, YamsView& v);
    void lancerPartie();

private:
    void jouerTour(joueur& j, bool estMaj);
};

#endif