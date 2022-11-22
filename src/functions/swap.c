#include "../../push_swap.h"

void    sa(t_sortvars *svars)
{
    ft_putstr_fd("sa\n", svars->log_fd);
    if (svars->stka_len <= 1)
        return ;
    ft_swap(&svars->stka_arr[0], &svars->stka_arr[1]);
}

void    sb(t_sortvars *svars)
{
    ft_putstr_fd("sb\n", svars->log_fd);
    if (svars->stkb_len <= 1)
        return ;
    ft_swap(&svars->stkb_arr[0], &svars->stkb_arr[1]);
}

void    ss(t_sortvars *svars)
{
    sa(svars);
    sb(svars);
}