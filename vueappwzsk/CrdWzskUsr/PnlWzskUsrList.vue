<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButFilterClick')"
						:value="1"
					>
						<v-icon color="white">{{contapp.ButFilterOn ? 'mdi-filter' : 'mdi-filter-off'}}</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskUsrList',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskUsrList.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzskUsrListDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wzsk.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Grp","Own","Prs","Srf","Usg","","Ste","","Lcl","","Ulv"],
							["grp","own","prs","srf","usg","ste","ste2","lcl","lcl2","ulv","ulv2"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWzskUsrListData": {
						"scrJref": this.scrJref,
						"StgIacQryWzskUsrList": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskUsrList"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskUsrListData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskUsrListData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskUsrList) this.contiac = dpcheng.ContIacWzskUsrList;
				if (dpcheng.ContInfWzskUsrList) this.continf = dpcheng.ContInfWzskUsrList;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.FeedFTos) this.feedFTos = dpcheng.FeedFTos;
				if (dpcheng.StatShrWzskUsrList) this.statshr = dpcheng.StatShrWzskUsrList;
				if (dpcheng.StgIacWzskUsrList) this.stgiac = dpcheng.StgIacWzskUsrList;
				if (dpcheng.TagWzskUsrList) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsrList);
					this.tag = dpcheng.TagWzskUsrList;
				}
				if (dpcheng.ListWzskQUsrList) this.rst = dpcheng.ListWzskQUsrList;
				if (dpcheng.StatAppQryWzskUsrList) this.statappqry = dpcheng.StatAppQryWzskUsrList;
				if (dpcheng.StatShrQryWzskUsrList) this.statshrqry = dpcheng.StatShrQryWzskUsrList;
				if (dpcheng.StgIacQryWzskUsrList) this.stgiacqry = dpcheng.StgIacQryWzskUsrList;
				if (dpcheng.ContInfWzskUsrList) {
					if (!this.continf.ButFilterOn) this.contapp.ButFilterOn = 0;
					else this.contapp.ButFilterOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWzskUsrList) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoGrp", text: this.tag.TcoGrp}, {value: "TcoOwn", text: this.tag.TcoOwn}, {value: "TcoPrs", text: this.tag.TcoPrs}, {value: "TcoSrf", text: this.tag.TcoSrf}, {value: "TcoUsg", text: this.tag.TcoUsg}, {value: "TcoSte", text: this.tag.TcoSte}, {value: "TcoLcl", text: this.tag.TcoLcl}, {value: "TcoUlv", text: this.tag.TcoUlv});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWzskQUsrList) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoGrp: rec["grp"], TcoOwn: rec["own"], TcoPrs: rec["prs"], TcoSrf: rec["srf"], TcoUsg: rec["usg"], TcoSte: rec["ste2"], TcoLcl: rec["lcl2"], TcoUlv: rec["ulv2"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskUsrListData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskUsrListData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statshr.srefIxWzskVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFCsiQst: null,

			feedFTos: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				ButFilterOn: 0,

				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
