#include "G4UImanager.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

class Test: public G4UImessenger {
    public:
        Test() {
                G4UIcmdWithADoubleAndUnit * cmd0 =
                    new G4UIcmdWithADoubleAndUnit("/test/setAngle0", this);
                cmd0->SetParameterName("angle0", false);
                cmd0->SetDefaultValue(0.);
                cmd0->SetUnitCategory("Angle");
                cmd0->SetDefaultUnit("deg");

                G4UIcmdWithADoubleAndUnit * cmd1 =
                    new G4UIcmdWithADoubleAndUnit("/test/setAngle1", this);
                cmd1->SetParameterName("angle1", false);
                cmd1->SetDefaultValue(0.);
                cmd1->SetUnitCategory("Angle");
        }

        void SetNewValue(G4UIcommand * command, G4String newValue) {
                G4cout << command->GetCommandName()
                       << " : "
                       << newValue
                       << G4endl;
        }
};

int main()
{
        new Test;

        G4UImanager * ui = G4UImanager::GetUIpointer();
        ui->ApplyCommand("/control/execute test.macro");

        return 0;
}

