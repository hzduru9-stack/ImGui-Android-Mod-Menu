#ifndef MENU
#define MENU
#include "ImGui/imgui.h"
#include "Themes.h"
#include "../Data/Fonts/Roboto-Regular.h"

using namespace ImGui;
static bool init;
int glWidth, glHeight;

// Aura Brawl Sayfa Yönetimi ve Buton Değişkenleri
static int aktifSayfa = 1;
bool xRayAteis = false;
bool otoNisan = false;
bool rankedMod = false;
bool kostumDegistirici = false;

void SetupImGui()
{
    if (!init)
    {
        auto context = ImGui::CreateContext();
        if (!context)
        {
            return;
        }
        ImGuiIO &io = ImGui::GetIO();
        ImFontConfig font_cfg;
        io.DisplaySize = ImVec2((float)glWidth, (float)glHeight);
        font_cfg.SizePixels = 22.0f;
        io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, 22, 22.0f, &font_cfg);

        io.IniFilename = NULL;
        init = true;
    }
}

void DrawAuraBrawlMenu() {
    // 1. ANA PANEL STİLİ (Mavi Arka Plan)
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 12.0f; // Köşeleri hafif yuvarla
    style.FrameRounding = 6.0f;   // Buton köşeleri
    
    // Panel Renk Ayarları (Mavi Tonlar)
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.25f, 0.65f, 0.95f); // Koyu Mavi Panel
    style.Colors[ImGuiCol_Border]   = ImVec4(0.00f, 0.45f, 0.95f, 1.00f); // Parlak Mavi Çerçeve
    
    // Ana Pencereyi Başlat
    ImGui::Begin("⚡ AURA BRAWL - MOD MENU ⚡", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    
    ImGui::Text("AURA BRAWL SEÇENEKLERİ");
    ImGui::Separator();
    
    // SAYFA SİSTEMİ MİMARİSİ
    if (aktifSayfa == 1) {
        // --- 1. SATIR BUTONLARI (Aktif/Yeşil Yapı)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.9f, 0.0f, 1.0f)); 
        if (ImGui::Button("X-RAY OTO-ATEŞ", ImVec2(140, 40))) {
            xRayAteis = !xRayAteis;
        }
        ImGui::SameLine(); // Yan yana dizilme
        
        if (ImGui::Button("OTOMATİK NİŞAN", ImVec2(140, 40))) {
            otoNisan = !otoNisan;
        }
        ImGui::PopStyleColor(); // Yeşil stili sıfırla

        ImGui::Spacing(); // Alt satır için boşluk

        // --- 2. SATIR BUTONLARI (Pasif/Mavi Yapı)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.4f, 0.9f, 1.0f));
        if (ImGui::Button("RANKED MODU", ImVec2(140, 40))) {
            rankedMod = !rankedMod;
        }
        ImGui::SameLine();
        if (ImGui::Button("KOSTÜM DEĞİŞTİRİCİ", ImVec2(140, 40))) {
            kostumDegistirici = !kostumDegistirici;
        }
        ImGui::PopStyleColor();
    }
    else if (aktifSayfa == 2) {
        ImGui::Text("Sayfa 2: İleride Eklenecek Özellikler...");
    }

    ImGui::Separator();
    
    // ALT GEZİNTİ VE SOSYAL MEDYA ALANI
    if (ImGui::Button("Önceki Sayfa", ImVec2(100, 35))) {
        if (aktifSayfa > 1) aktifSayfa--;
    }
    
    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.15f, 0.5f, 1.0f));
    if (ImGui::Button("t.me/aurabrawl", ImVec2(120, 35))) {
        // Telegram yönlendirmesi
    }
    ImGui::PopStyleColor();
    
    ImGui::SameLine();
    if (ImGui::Button("Sonraki Sayfa", ImVec2(100, 35))) {
        if (aktifSayfa < 4) aktifSayfa++;
    }

    ImGui::End();
}

#endif
