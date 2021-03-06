/*
    Copyright (C) 2014-2016 Islog

    This file is part of Leosac.

    Leosac is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Leosac is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "ConditionBase.hpp"
#include "core/auth/AuthFwd.hpp"

namespace Leosac
{
namespace Module
{
namespace WebSockAPI
{
namespace Conditions
{
/**
 * A `Condition` that will return true if the current user is
 * a member of a group.
 *
 * The current user is retrieved from the RequestContext object.
 *
 * @note It's possible to also check for a minimal rank in the group.
 */
class IsInGroup : public ConditionBase
{
  public:
    IsInGroup(RequestContext ctx, Auth::GroupId group);

    /**
     * Check that an user is in the group and has a minimal rank.
     * @param min_rank Minimal rank for the user to be consided a part of the group.
     * @return
     */
    IsInGroup(RequestContext ctx, Auth::GroupId group, Auth::GroupRank min_rank);

    bool operator()();

  private:
    Auth::GroupId group_id_;
    Auth::GroupRank min_rank_;
};
}
}
}
}
