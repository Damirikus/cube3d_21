#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin;

	begin = (t_list *)malloc(sizeof(t_list));
	if (!begin)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
