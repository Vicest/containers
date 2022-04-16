/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:39:57 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/08 20:07:43 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <vector>
#ifdef STD
namespace test = std;
#else
namespace test = ft;
# include "../vector.hpp"
#endif

int	main(void)
{
	const test::vector<int>	cempty;
}
