
class APP(dialog) : RSC(guiMenu) {
    idd = IDD_GUI_CRATE;
    name = "Cratespawner";

    onLoad = QUOTE(uiNamespace setVariable [ARR_2('EGVAR(gui_main,dialog)',_this select 0)]; [ARR_2('GVAR(dialog)',true)] call EFUNC(gui,blur); _this call EFUNC(gui_main,OnLoad); _this call FUNC(OnLoad););
    onUnload = QUOTE([ARR_2('GVAR(dialog)',false)] call EFUNC(gui,blur);_this call EFUNC(gui_main,OnUnload););

    controlsBackground[] = {
        background_header,
        background_body,
        background_gradiend,
        background_items
    };
    controls[] = {
        //background_logo,
        headertext,
        clock,
        player_button,
        menu_button,
        crate_button1,
        crate_button2,
        crate_button3,
        crate_button4,
        crate_button5,
        crate_button6,
        crate_button7,
        crate_button8,
        crate_button9,
        crate_button10,
        crate_button11,
        crate_button12,
        crate_button13,
        crate_button14,
        crate_button15,
        crate_button16,
        crate_button17,
        itemlist,
        itemfilter,
        itemfilter_watermark,

        boxtitle,
        boxlist,
        inventorytitle,
        inventory
    };

    class background_header : background_header {
        text = CSTRING(header);
    };

    class background_body : background_body {
        colorBackground[] = COLOR_CRATE_BACKGROUND;
    };

    class background_gradiend : background_gradiend {
        colorText[] = COLOR_CRATE_BACKGROUND_GRADIEND;
    };

    class background_items: RSC(BaseText) {
        x = GUI_DISP_X+GUI_DISP_W*4;
        y = GUI_DISP_Y+GUI_DISP_H*10;
        w = GUI_DISP_WAbs-GUI_DISP_W*22;
        h = GUI_DISP_HAbs-GUI_DISP_H*18;
        style = "0x02";
        text = "";
        colorText[] = COLOR_DISABLED;
        colorBackground[] = COLOR_CRATE_BACKGROUND2;
    };

    class itemlist_button_add : RSC(BaseButton) {
        idc = IDC_GUI_CRATE_ITEMLIST_ADD;
        text = "+";
        borderSize = 0;
        colorShadow[] = {0,0,0,0};
        action = QUOTE([ARR_2((ctrlParent (_this select 0)) displayCtrl IDC_GUI_CRATE_ITEMLIST,true)] call FUNC(add);false);
    };
    class inventory_button_add : itemlist_button_add {
        idc = IDC_GUI_CRATE_INVENTORY_ADD;
    };

    class itemlist_button_reduce : itemlist_button_add {
        idc = IDC_GUI_CRATE_ITEMLIST_REDUCE;
        text = "-";
        action = QUOTE([ARR_2((ctrlParent (_this select 0)) displayCtrl IDC_GUI_CRATE_ITEMLIST,false)] call FUNC(add);false);
    };
    class inventory_button_reduce : itemlist_button_reduce {
        idc = IDC_GUI_CRATE_INVENTORY_REDUCE;
    };

    class itemlist : RSC(BaseListboxN) {
        idc = IDC_GUI_CRATE_ITEMLIST;
        access = 2;
        x = GUI_DISP_X+GUI_DISP_W*3;
        y = GUI_DISP_Y+GUI_DISP_H*10;
        w = GUI_DISP_W*74;
        h = GUI_DISP_HAbs-GUI_DISP_H*34;
        rowHeight = GUI_DISP_H*4;
        sizeEx = GUI_DISP_H*3.5;
        columns[] = {GUI_DISP_W*5,GUI_DISP_W*16,GUI_DISP_W*21,GUI_DISP_W*28};
        drawSideArrows = 1;
        idcLeft = IDC_GUI_CRATE_ITEMLIST_REDUCE;
        idcRight = IDC_GUI_CRATE_ITEMLIST_ADD;
        colorText[] = COLOR_CRATE_ITEMLIST_TEXT;
    };

    class itemfilter : RSC(BaseEditBox) {
        idc = IDC_GUI_CRATE_FILTER;
        x = GUI_DISP_X+GUI_DISP_W*3;
        y = GUI_DISP_Y+GUI_DISP_H*40;
        w = GUI_DISP_W*74;
        h = GUI_DISP_H*5;
        sizeEx = GUI_DISP_H*3.5;
    };

    class itemfilter_watermark : RSC(BaseText) {
        idc = IDC_GUI_CRATE_FILTER_WATERMARK;
        x = GUI_DISP_X+GUI_DISP_W*3;
        y = GUI_DISP_Y+GUI_DISP_H*40;
        w = GUI_DISP_W*74;
        h = GUI_DISP_H*5;
        sizeEx = GUI_DISP_H*3.5;
        text = CSTRING(FILTER);
        colorBackground[] = COLOR_CRATE_EDIT_BACKGROUND;
        colorText[] = COLOR_CRATE_EDIT_TEXT_BACK;
    };

    class crate_button1 : RSC(BaseButton) {
        idc = IDC_GUI_CRATE_BTTN1;
        x = GUI_DISP_X+GUI_DISP_W*6;
        y = GUI_DISP_Y+GUI_DISP_H*10;
        w = GUI_DISP_W*9;
        h = GUI_DISP_H*9;
        shadow = 0;
        sizeEx = GUI_DISP_W*9;
        color[] = COLOR_DISABLED;

        colorBackground[] = COLOR_BASE_GREY_LIGHT;
        colorBackgroundActive[] = COLOR_BASE_GREY_LIGHT;
        colorFocused[] = COLOR_BASE_GREY;

        colorText[] = COLOR_BASE_BLACK;
        colorTextSelect[] = COLOR_BASE_GREY_LIGHT;

        colorShadow[] = COLOR_BASE_GREY_LIGHT;
        colorBorder[] = COLOR_BASE_GREY_LIGHT;

        colorDisabled[] = {0.1, 0.1, 0.1, 0.4};
        colorBackgroundDisabled[] = {0, 0, 0, 0.2};

        offsetX = 0;
        offsetY = 0;

        toolTip = CSTRING(BTTN_1);
        style = 48;
        text = "A3\ui_f\data\gui\cfg\Hints\rifle_ca.paa";
    };
    class crate_button2 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN2;
        y = GUI_DISP_H*20;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*0);
        toolTip = CSTRING(BTTN_2);
        text = "A3\ui_f\data\gui\cfg\Hints\automatic_ca.paa";
    };
    class crate_button3 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN3;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*1);
        toolTip = CSTRING(BTTN_3);
        text = "A3\ui_f\data\gui\cfg\Hints\Sniper_ca.paa";
    };
    class crate_button4 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN4;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*1);
        toolTip = CSTRING(BTTN_4);
        text = "A3\ui_f\data\gui\cfg\Hints\Launcher_ca.paa";
    };
    class crate_button5 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN5;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*2);
        toolTip = CSTRING(BTTN_5);
        text = "A3\ui_f\data\gui\cfg\Hints\Handgun_ca.paa";
    };
    class crate_button6 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN6;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*2);
        toolTip = CSTRING(BTTN_6);
        text = "A3\ui_f\data\gui\cfg\Hints\Optics_ca.paa";
    };
    class crate_button7 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN7;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*3);
        toolTip = CSTRING(BTTN_7);
        text = "A3\ui_f\data\gui\cfg\Hints\Granades_ca.paa";
    };
    class crate_button8 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN8;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*3);
        toolTip = CSTRING(BTTN_8);
        text = "A3\ui_f\data\gui\cfg\Hints\Mines_ca.paa";
    };
    class crate_button9 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN9;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*4);
        toolTip = CSTRING(BTTN_9);
        text = "A3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
    };
    class crate_button10 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN10;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*4);
        toolTip = CSTRING(BTTN_10);
        text = "A3\ui_f\data\gui\Rsc\RscDisplayArsenal\vest_ca.paa";
    };
    class crate_button11 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN11;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*5);
        toolTip = CSTRING(BTTN_11);
        text = "A3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
    };
    class crate_button12 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN12;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*5);
        toolTip = CSTRING(BTTN_12);
        text = "A3\ui_f\data\gui\cfg\Hints\Gear_CA.paa";
    };
    class crate_button13 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN13;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*6);
        toolTip = CSTRING(BTTN_13);
        text = "A3\ui_f\data\gui\cfg\Hints\CallSupport_CA.paa";
    };
    class crate_button14 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN14;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*6);
        toolTip = CSTRING(BTTN_14);
        text = "A3\ui_f\data\gui\cfg\Hints\Direction_ca.paa";
    };
    class crate_button15 : crate_button1 {
        idc = IDC_GUI_CRATE_BTTN15;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*7);
        toolTip = CSTRING(BTTN_15);
        text = "A3\ui_f\data\gui\cfg\Hints\Injury_ca.paa";
    };
    class crate_button16 : crate_button2 {
        idc = IDC_GUI_CRATE_BTTN16;
        x = GUI_DISP_X+GUI_DISP_W*(6+9*7);
        toolTip = CSTRING(BTTN_16);
        text = "A3\ui_f\data\gui\cfg\Hints\Take_ca.paa";
    };

    class boxtitle : RSC(BaseText) {
        idc = ID_GUI_CRATE_BOXLIST_HEADER;
        x = GUI_DISP_X + GUI_DISP_W*90;
        y = GUI_DISP_Y + GUI_DISP_H*10;
        w = GUI_DISP_W*60
        h = GUI_DISP_H*6;
        text = CSTRING(header_box);
    };

    class boxlist : RSC(BaseCombobox) {
        idc = IDC_GUI_CRATE_BOXLIST;
        x = GUI_DISP_X + GUI_DISP_W*90;
        y = GUI_DISP_Y + GUI_DISP_H*18;
        w = GUI_DISP_W*60
        h = GUI_DISP_H*6;
        sizeEx = GUI_DISP_H*6;
        rowHeight = GUI_DISP_H*6;
        wholeHeight = GUI_DISP_H*50;
        onLBSelChanged = QFUNC(onBoxChanged);
    };

    class inventorytitle : RSC(BaseText) {
        idc = ID_GUI_CRATE_INVENTORY_HEADER;
        x = GUI_DISP_X + GUI_DISP_W*90;
        y = GUI_DISP_Y + GUI_DISP_H*10;
        w = GUI_DISP_W*60
        h = GUI_DISP_H*6;
        text = CSTRING(header_inventory);
    };

    class inventory : itemlist {
        idc = IDC_GUI_CRATE_INVENTORY;
        x = GUI_DISP_X + GUI_DISP_W*90;
        y = GUI_DISP_Y + GUI_DISP_H*30;
        w = GUI_DISP_W*60;
        h = GUI_DISP_H*40;
        idcLeft = IDC_GUI_CRATE_INVENTORY_REDUCE;
        idcRight = IDC_GUI_CRATE_INVENTORYT_ADD;
    };
};
