<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButClipboardClick')"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButFilterClick')"
					>
						<v-icon color="white">mdi-filter</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-data-table
				:headers="contapp.tcos"
				:items="contapp.rows"
				:items-per-page="10"
				class="elevation-1"
			/>

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
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskSesList',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskSesList.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskSesListDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskSesList"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskSesListData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskSesListData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskSesList) this.contiac = dpcheng.ContIacWzskSesList;
				if (dpcheng.ContInfWzskSesList) this.continf = dpcheng.ContInfWzskSesList;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.FeedFTos) this.feedFTos = dpcheng.FeedFTos;
				if (dpcheng.StatShrWzskSesList) this.statshr = dpcheng.StatShrWzskSesList;
				if (dpcheng.StgIacWzskSesList) this.stgiac = dpcheng.StgIacWzskSesList;
				if (dpcheng.TagWzskSesList) {
					Wzsk.unescapeBlock(dpcheng.TagWzskSesList);
					this.tag = dpcheng.TagWzskSesList;
				}
				if (dpcheng.ListWzskQSesList) this.rst = dpcheng.ListWzskQSesList;
				if (dpcheng.StatAppQryWzskSesList) this.statappqry = dpcheng.StatAppQryWzskSesList;
				if (dpcheng.StatShrQryWzskSesList) this.statshrqry = dpcheng.StatShrQryWzskSesList;
				if (dpcheng.StgIacQryWzskSesList) this.stgiacqry = dpcheng.StgIacQryWzskSesList;

				if (dpcheng.TagWzskSesList) {
					var tcos = [];

					for (const [key, value] of Object.entries(this.tag)) {
						if (key.indexOf("Tco") == 0) tcos.push({value: key, text: value})
					}

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWzskQSesList) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						rows.push({TcoUsr: rec["usr"], TcoSta: rec["sta"], TcoSto: rec["sto"], TcoIp: rec["ip"]})
					}

					this.contapp.rows = rows;
				}

				/*
				<!-- IP mergeDpchEngData - END -->
				*/
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
				if (srefIxWzskVDpch == "DpchEngWzskSesListData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskSesListData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			fiFCsiQst: function() {
				for (var i = 0; i < this.feedFCsiQst.length; i++)
					if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return null
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contapp: {
				tcos: [
					{
						value: "TcoUsr",
						text: "User"
					},
					{
						value: "TcoSta",
						text: "Start"
					},
					{
						value: "TcoSto",
						text: "Stop"
					},
					{
						value: "TcoIp",
						text: "IP"
					}
				],
				rows: [
					{
						jnum: 1,
						TcoUsr: "temp / Jack Smith",
						TcoSta: "21-10-2021 14:03:47",
						TcoSto: "",
						TcoIp: "127.0.0.1"
					},
					{
						jnum: 2,
						TcoUsr: "wzskuser / Emily Johnson",
						TcoSta: "27-10-2021 14:04:49",
						TcoSto: "",
						TcoIp: "127.0.0.1"
					}
				]
			},

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

			stgiacqry: null
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
