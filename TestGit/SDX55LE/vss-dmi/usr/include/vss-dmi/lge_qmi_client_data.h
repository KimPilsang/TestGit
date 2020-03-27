#ifndef __LGE_QMI_CLIENT_DATA_H__
#define __LGE_QMI_CLIENT_DATA_H__

typedef int (*init_t)(qmi_service_info *, qmi_idl_service_object_type, qmi_client_ind_cb,
        void *, qmi_client_os_params *, qmi_client_type *);
typedef int (*release_t)(qmi_client_type);
typedef int (*get_service_list_t)(qmi_idl_service_object_type, qmi_service_info *,
        unsigned int *, unsigned int *);
typedef int (*notifier_init_t)(qmi_idl_service_object_type, qmi_client_os_params *,
        qmi_client_type *);
typedef int (*send_msg_sync_t)(qmi_client_type, unsigned int, void *, unsigned int,
        void *, unsigned int, unsigned int);
typedef int (*register_error_cb_t)(qmi_client_type, qmi_client_error_cb, void *);

struct qmi_client_data {
    void *qmi_client;
    init_t init;
    release_t release;
    get_service_list_t get_service_list;
    notifier_init_t notifier_init;
    send_msg_sync_t send_msg_sync;
    register_error_cb_t register_error_cb;
};

#endif // __LGE_QMI_CLIENT_DATA_H__
