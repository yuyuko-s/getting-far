#include "LevelInfo.hpp";
#include <Geode/utils/web.hpp>
using namespace geode::prelude;

/*
CREDIT: EclipseMenu
*/
LevelDifficulty LevelInfo::getLevelDifficulty(GJGameLevel* level) {
    if (level->m_autoLevel) return LevelDifficulty::Auto;
    auto diff = level->m_difficulty;

    if (level->m_ratingsSum != 0)
        diff = static_cast<GJDifficulty>(level->m_ratingsSum / 10);

    if (level->m_demon > 0) {
        switch (level->m_demonDifficulty) {
        case 3: return LevelDifficulty::EasyDemon;
        case 4: return LevelDifficulty::MediumDemon;
        case 5: return LevelDifficulty::InsaneDemon;
        case 6: return LevelDifficulty::ExtremeDemon;
        default: return LevelDifficulty::HardDemon;
        }
    }

    switch (diff) {
    case GJDifficulty::Easy: return LevelDifficulty::Easy;
    case GJDifficulty::Normal: return LevelDifficulty::Normal;
    case GJDifficulty::Hard: return LevelDifficulty::Hard;
    case GJDifficulty::Harder: return LevelDifficulty::Harder;
    case GJDifficulty::Insane: return LevelDifficulty::Insane;
    case GJDifficulty::Demon: return LevelDifficulty::HardDemon;
    default: return LevelDifficulty::NA;
    }
}

std::string LevelInfo::getDifficultyImage(LevelDifficulty difficulty)
{
    // discord as asset storage Lol
    switch (difficulty) {
    case LevelDifficulty::ExtremeDemon: return "https://cdn.discordapp.com/attachments/741003526502613122/1333270514579542097/difficulty.png?ex=6798f12d&is=67979fad&hm=3c5eb30755eb7214a07913e306fc0a167abb71c75e7cd247f8572b33fa193430&";
    case LevelDifficulty::InsaneDemon: return "https://cdn.discordapp.com/attachments/741003526502613122/1333270517154709504/difficulty.png?ex=6798f12e&is=67979fae&hm=25f2d6664e02127f4a803dee943c8a639c252e2eafc59afb0c8c3f27d444d91e&";
    case LevelDifficulty::HardDemon: return "https://cdn.discordapp.com/attachments/741003526502613122/1333496996421570661/difficulty.png?ex=67991b5b&is=6797c9db&hm=950a4686ea845c4d982b92c66e99099b6b54ba2a314fdc731262898d99400bad&";
    case LevelDifficulty::MediumDemon: return "https://cdn.discordapp.com/attachments/741003526502613122/1333270510963916902/difficulty.png?ex=6798f12c&is=67979fac&hm=06725cfd2ea2ca5a6d2eef8073234ab5e585825b8e1b7f812e24d573c1d1695c&";
    case LevelDifficulty::EasyDemon: return "https://cdn.discordapp.com/attachments/741003526502613122/1332168247755145328/difficulty.png?ex=67998bdc&is=67983a5c&hm=bf276cec722dcae0e034f79b92200a80531a3eb315fa9fe888f319359aff349c&";
    default: return "https://cdn.discordapp.com/attachments/1333627396842197146/1333908505169498214/difficulty.png?ex=679a9a9a&is=6799491a&hm=a879219d3f8371f102ae36d5eefe9c1da2321679623d974921290ddd80f77b00&";
    }
}

