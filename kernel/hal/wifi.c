/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include <stdio.h>
#include <hal/hal.h>

static AOS_DLIST_HEAD(g_wifi_module);

hal_wifi_module_t *hal_wifi_get_default_module(void)
{
    hal_wifi_module_t *m = 0;

    if (dlist_empty(&g_wifi_module)) {
        return 0;
    }

    m = dlist_first_entry(&g_wifi_module, hal_wifi_module_t, base.list);

    return m;
}
EXPORT_SYMBOL_K(1, hal_wifi_get_default_module, \
    "hal_wifi_module_t *hal_wifi_get_default_module(void)")

void hal_wifi_register_module(hal_wifi_module_t *module)
{
    dlist_add_tail(&module->base.list, &g_wifi_module);

}
EXPORT_SYMBOL_K(1, hal_wifi_register_module, \
    "void hal_wifi_register_module(hal_wifi_module_t *module)")

int hal_wifi_init(void)
{
    int          err = 0;
    dlist_t *t;

    /* do low level init */
    dlist_for_each(t, &g_wifi_module) {
        hal_wifi_module_t *m = (hal_wifi_module_t *)t;
        m->init(m);
    }

    return err;
}
EXPORT_SYMBOL_K(1, hal_wifi_init, "int hal_wifi_init(void)")

void hal_wifi_get_mac_addr(hal_wifi_module_t *m, uint8_t *mac)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->get_mac_addr(m, mac);
}
EXPORT_SYMBOL_K(1, hal_wifi_get_mac_addr, "void hal_wifi_get_mac_addr(hal_wifi_module_t *m, uint8_t *mac)")


int hal_wifi_start(hal_wifi_module_t *m, hal_wifi_init_type_t *init_para)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->start(m, init_para);
}
EXPORT_SYMBOL_K(1, hal_wifi_start, "int hal_wifi_start(hal_wifi_module_t *m, hal_wifi_init_type_t *init_para)")

int  hal_wifi_start_adv(hal_wifi_module_t *m, hal_wifi_init_type_adv_t *init_para_adv)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->start_adv(m, init_para_adv);
}
EXPORT_SYMBOL_K(1, hal_wifi_start_adv, "int hal_wifi_start_adv(hal_wifi_module_t *m, hal_wifi_init_type_adv_t *init_para_adv)")

int  hal_wifi_get_ip_stat(hal_wifi_module_t *m, hal_wifi_ip_stat_t *out_net_para, hal_wifi_type_t wifi_type)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->get_ip_stat(m, out_net_para, wifi_type);
}
EXPORT_SYMBOL_K(1, hal_wifi_get_ip_stat, "int hal_wifi_get_ip_stat(hal_wifi_module_t *m, hal_wifi_ip_stat_t *out_net_para, hal_wifi_type_t wifi_type)")

int  hal_wifi_get_link_stat(hal_wifi_module_t *m, hal_wifi_link_stat_t *out_stat)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->get_link_stat(m, out_stat);
}
EXPORT_SYMBOL_K(1, hal_wifi_get_link_stat, "int hal_wifi_get_link_stat(hal_wifi_module_t *m, hal_wifi_link_stat_t *out_stat)")

void hal_wifi_start_scan(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->start_scan(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_start_scan, "void hal_wifi_start_scan(hal_wifi_module_t *m)")

void hal_wifi_start_scan_adv(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->start_scan_adv(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_start_scan_adv, "void hal_wifi_start_scan_adv(hal_wifi_module_t *m)")

int hal_wifi_power_off(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->power_off(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_power_off, "int hal_wifi_power_off(hal_wifi_module_t *m)")

int hal_wifi_power_on(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->power_on(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_power_on, "int hal_wifi_power_on(hal_wifi_module_t *m)")

int hal_wifi_suspend(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->suspend(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_suspend, "int hal_wifi_suspend(hal_wifi_module_t *m)")

int hal_wifi_suspend_station(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->suspend_station(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_suspend_station, "int hal_wifi_suspend_station(hal_wifi_module_t *m)")

int hal_wifi_suspend_soft_ap(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->suspend_soft_ap(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_suspend_soft_ap, "int hal_wifi_suspend_soft_ap(hal_wifi_module_t *m)")

int hal_wifi_set_channel(hal_wifi_module_t *m, int ch)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->set_channel(m, ch);
}
EXPORT_SYMBOL_K(1, hal_wifi_set_channel, "int hal_wifi_set_channel(hal_wifi_module_t *m, int ch)")

void hal_wifi_start_wifi_monitor(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->start_monitor(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_start_wifi_monitor, "void hal_wifi_start_wifi_monitor(hal_wifi_module_t *m)")

void hal_wifi_stop_wifi_monitor(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->stop_monitor(m);
}
EXPORT_SYMBOL_K(1, hal_wifi_stop_wifi_monitor, "void hal_wifi_stop_wifi_monitor(hal_wifi_module_t *m)")

void hal_wifi_register_monitor_cb(hal_wifi_module_t *m, monitor_data_cb_t fn)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->register_monitor_cb(m, fn);
}
EXPORT_SYMBOL_K(1, hal_wifi_register_monitor_cb, "void hal_wifi_register_monitor_cb(hal_wifi_module_t *m, monitor_data_cb_t fn)")

void hal_wifi_install_event(hal_wifi_module_t *m, const hal_wifi_event_cb_t *cb)
{
    m->ev_cb = cb;
}
EXPORT_SYMBOL_K(1, hal_wifi_install_event, "void hal_wifi_install_event(hal_wifi_module_t *m, const hal_wifi_event_cb_t *cb)")

void hal_wlan_register_mgnt_monitor_cb(hal_wifi_module_t *m, monitor_data_cb_t fn)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    m->register_wlan_mgnt_monitor_cb(m, fn);
}
EXPORT_SYMBOL_K(1, hal_wlan_register_mgnt_monitor_cb, "void hal_wlan_register_mgnt_monitor_cb(hal_wifi_module_t *m, monitor_data_cb_t fn)")

int hal_wlan_send_80211_raw_frame(hal_wifi_module_t *m, uint8_t *buf, int len)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    return m->wlan_send_80211_raw_frame(m, buf, len);
}
EXPORT_SYMBOL_K(1, hal_wlan_send_80211_raw_frame, "int hal_wlan_send_80211_raw_frame(hal_wifi_module_t *m, uint8_t *buf, int len)")

void hal_wifi_start_debug_mode(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    if (m->start_debug_mode == NULL) {
        return;
    }

    return m->start_debug_mode(m);
}

void hal_wifi_stop_debug_mode(hal_wifi_module_t *m)
{
    if (m == NULL) {
        m = hal_wifi_get_default_module();
    }

    if (m->stop_debug_mode == NULL) {
        return;
    }

    return m->stop_debug_mode(m);
}