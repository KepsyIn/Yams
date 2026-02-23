#include "../include/model/YamsModel.h"
#include "../include/view/YamsView.h"
#include "../include/controller/YamsController.h"

int main()
{
    YamsModel model(2, 6); // 2 joueurs, 6 faces
    YamsView view;
    YamsController controller(model, view);

    controller.lancerPartie();
    return 0;
}