#include "G4UImanager.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

#include <assert.h>


class Test: public G4UImessenger {
    public:
        Test() {
                G4UIcmdWithADoubleAndUnit * cmd0 =
                    new G4UIcmdWithADoubleAndUnit("/test/setAngle0", this);
                cmd0->SetParameterName("angle0", false);
                cmd0->SetDefaultValue(0.);
                cmd0->SetUnitCategory("Angle");
                cmd0->SetDefaultUnit("deg");
                fCommands[0] = static_cast<G4UIcommand *>(cmd0);

                G4UIcmdWithADoubleAndUnit * cmd1 =
                    new G4UIcmdWithADoubleAndUnit("/test/setAngle1", this);
                cmd1->SetParameterName("angle1", false);
                cmd1->SetDefaultValue(0.);
                cmd1->SetUnitCategory("Angle");
                fCommands[1] = static_cast<G4UIcommand *>(cmd1);
        }

        ~Test() {
                for (unsigned i = 0; i < fNbOfCommands; i++)
                        delete fCommands[i];
        }

        void SetNewValue(G4UIcommand * command, G4String newValue) {
                G4cout << command->GetCommandName()
                       << " : "
                       << newValue
                       << G4endl;

                const G4double angle =
                    G4UIcmdWithADoubleAndUnit::GetNewDoubleValue(newValue);
                for (unsigned i = 0; i < fNbOfCommands; i++) {
                        if (command == fCommands[i]) {
                                fAngles[i] = angle;
                                break;
                        }
                }
        }

        G4double GetAngle(G4int index) const {
                return fAngles[index];
        }

    private:
        static const unsigned fNbOfCommands = 2;
        G4UIcommand * fCommands[fNbOfCommands];
        G4double fAngles[fNbOfCommands];
};


int main()
{
        Test * test = new Test;

        G4UImanager * ui = G4UImanager::GetUIpointer();
        ui->ApplyCommand("/control/useDoublePrecision");
        ui->ApplyCommand("/control/execute test.macro");

        assert(test->GetAngle(0) == test->GetAngle(1));

        delete test;
        exit(EXIT_FAILURE);
}
