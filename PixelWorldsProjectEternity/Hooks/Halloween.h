#ifndef CSY_HALLOWEEN_H
#define CSY_HALLOWEEN_H

static bool EnableHalloweenInfoLabel = false;

void DrawHalloweenMenu() {
    if (EnableHalloweenInfoLabel && !checkIsPlayerInMenu && worldType == 4) {
        ImGui::Begin(OBFUSCATE("Halloween Info Label"), &EnableHalloweenInfoLabel,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize |ImGuiWindowFlags_NoCollapse);
        ImGui::End();
    }
}

#endif //CSY_HALLOWEEN_H
