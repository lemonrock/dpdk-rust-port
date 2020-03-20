/* Flow director report status
 * It defines what will be reported if FDIR entry is matched.
 */
enum i40e_fdir_status
{
	I40E_FDIR_NO_REPORT_STATUS = 0, /* Report nothing. */
	I40E_FDIR_REPORT_ID,            /* Only report FD ID. */
	I40E_FDIR_REPORT_ID_FLEX_4,     /* Report FD ID and 4 flex bytes. */
	I40E_FDIR_REPORT_FLEX_8,        /* Report 8 flex bytes. */
};
